#ifndef __MESSAGE_H
#define __MESSAGE_H
#include <set>
#include <string>
#include <iostream>

using namespace std;

class Floder;

class Message {
    friend void show(Message& m);
    public:
        Message(const string& str = "") : content(str) {};
        Message(const Message& org) : content(org.content), floders(org.floders) {
            add_to_floder(org);
        }
        Message& operator=(const Message& org) {
            remove_from_floder();
            content = org.content;
            floders = org.floders;
            add_to_floder(org);
            return *this;
        }
        ~Message() {
            remove_from_floder();
        }
        const string& getConent() {
            return content;
        }
        void save(Floder& dst);
        void remove(Floder& dst);
        void addFld(Floder* dst) {
            floders.insert(dst);
        }
        void rmvFld(Floder* dst) {
            floders.erase(dst);
        }
    private:
        void add_to_floder(const Message& org);
        void remove_from_floder();
        string content;
        set<Floder*> floders;
};

class Floder {
    friend void show(Floder& f);
    public:
        Floder(const string& str = "") : name(str) {};
        Floder(const Floder& org){
            name = org.name;
            msgs = org.msgs;
            add_to_msg(org);
        }
        Floder& operator=(const Floder& org) {
            remove_from_msg();
            name = org.name;
            msgs = org.msgs;
            add_to_msg(org);
            return *this;
        }
        ~Floder(){
            remove_from_msg();
        }
        const string& getName() {
            return name;
        }
        void addmsg(Message* m) {
            msgs.insert(m);
        }
        void rmvmsg(Message* m) {
            msgs.erase(m);
        }
    private:
        void add_to_msg(const Floder& org) {
            for(auto& m : org.msgs) {
                m->addFld(this);
            }
        }
        void remove_from_msg() {
            for(auto& m : msgs) {
                m->rmvFld(this);
            }
        }
        set<Message*> msgs;
        string name;
};

void Message::save(Floder& dst)
{
    floders.insert(&dst);
    dst.addmsg(this);
}

void Message::remove(Floder& dst)
{
    floders.erase(&dst);
    dst.rmvmsg(this);
}

void Message::add_to_floder(const Message& org)
{
    for (auto &f : org.floders)
        f->addmsg(this);
}

void Message::remove_from_floder()
{
    for (auto &f : floders)
        f->rmvmsg(this);
}

void show(Floder& f)
{
    int index = 0;
    cout << "Floder: " << f.name << "(" << f.msgs.size() << ")" << endl;
    for (auto& m : f.msgs) {
        cout << index++ << " :" << endl;
        cout << m->getConent() << endl;
    }
}

void show(Message& m)
{
    int index = 0;
    cout << "Message: " << m.content << "(" << m.floders.size() << ")" << endl;
    for (auto& f : m.floders) {
        cout << index++ << " :" << endl;
        cout << f->getName() << endl;
    }
}

#endif
