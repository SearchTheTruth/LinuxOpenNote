#include <linux/seq_file.h>
#include <linux/proc_fs.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/err.h>
#include <linux/slab.h>

#define TAG		"SEQ"
#define SEQ_DEBUG
#define ELE_ARRAY_SIZE	(25)

/*debug macro*/
#undef	PDEBUG
#ifdef	SEQ_DEBUG
#	ifdef	__KERNEL__
#		define	PDEBUG(fmt, args...)	printk(KERN_DEBUG TAG fmt, ## args)
#	else
#		define	PDEBUG(fmt, args...)	fprintf(stderr, fmt, ## args)
#	endif
#else
#	define	PDEBUG(fmt, args...)
#endif

#undef PDEBUGG
#define PDEBUGG(fmt, args...)

struct element{
	char name[10];
	int id;
};

/*public variable*/
static struct element element_array[ELE_ARRAY_SIZE];
static struct proc_dir_entry *proc_for_seq;
static loff_t *index;

/*
 *
 *@pos: file position.
 *@return: an iterator which will start reading at that position
 */
static void *seq_ops_start(struct seq_file *m, loff_t *pos)
{
	PDEBUG("%s\n", __func__);
	PDEBUG("*pos = %d\n", (int)*pos);
	if ((NULL == pos) || (0 != *pos))
	{
		return NULL;
	}
	
	index = pos;
	
	return element_array;
}

/*
 *move the iterator forward to the next position in the sequence.
 *@v:	base position
 *@pos: next position
 *@return: a new iterator, or NULL if the sequence is complete.
 */
static void *seq_ops_next(struct seq_file *m, void *v, loff_t *pos)
{
	PDEBUG("%s\n", __func__);
	(*pos)++;

	if (*pos >= ELE_ARRAY_SIZE)
	{
		return NULL;
	}
	
	return &element_array[*pos];
}

/*
 *format the object currently pointed to by the iterator for output.
 *@v:point to iterator that return from start() or next()
 *@return:zero, or an error code if something goes wrong.
 */
static int seq_ops_show(struct seq_file *m, void *v)
{
	struct element *ele_ptr = v;

	PDEBUG("%s\n", __func__);
	seq_printf(m, "name = %s, id = %d\n", ele_ptr->name, ele_ptr->id);
	PDEBUGG("v_adres = %p, name = %s, id = %d\n", ele_ptr, ele_ptr->name, ele_ptr->id);
	PDEBUGG("==============================================");
	return 0;
}

/*
 *This function called when iteration is complete,clean everything up,return dynamic memory was allocated for iteration
 *@v:point to address that return from start()
 *
 */
static void seq_ops_stop(struct seq_file *m, void *v)
{
	*index = 0;
	PDEBUG("%s\n", __func__);
}


static struct seq_operations seq_ops = {
	.start = seq_ops_start,
	.next = seq_ops_next,
	.show = seq_ops_show,
	.stop = seq_ops_stop,
};

static int proc_ops_open(struct inode *inode, struct file *file)
{
	
	return seq_open(file, &seq_ops);
}


static struct file_operations proc_fops = {
	.owner = THIS_MODULE,
	.open = proc_ops_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = seq_release,
};

static int __init seq_practice_init(void)
{
	int i;
	PDEBUG("%sinvoked!!,version:1.1\n", __func__);

	memset(element_array, 0, sizeof(element_array));
	for(i = 0; i < ELE_ARRAY_SIZE; i++)
	{
		snprintf(element_array[i].name, 10, "SEQ_%c", 'A'+i);
		element_array[i].id = i;
		PDEBUG("[%d] addr:%p, name:%s, id:%d\n", i, &element_array[i], element_array[i].name, element_array[i].id);
	}
	PDEBUG("int * = %d, struct element * = %d\n", (int)sizeof(int *), (int)sizeof(struct element *));
	proc_for_seq = proc_create("seq_practice", 0, NULL, &proc_fops);

	return PTR_ERR(proc_for_seq);
}

static void __exit seq_practice_exit(void)
{
	proc_remove(proc_for_seq);
}

module_init(seq_practice_init);
module_exit(seq_practice_exit);

MODULE_AUTHOR("JJ");
MODULE_LICENSE("GPL");
