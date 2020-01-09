#ifndef __ADVANCEQUERY_H
#define __ADVANCEQUERY_H
#include "TextQuery.h"
#include <string>
#include <memory>

using namespace std;

class Query_base {
    friend class Query;
    protected:
        using line_no = TextQuery::line_no;
        virtual ~Query_base() = default;
    private:
        virtual QueryResult eval(TextQuery &t) const = 0;
        virtual string rep() const = 0;
};

class WordQuery : public Query_base {
    friend class Query;
    private:
        WordQuery(const string &s) : word(s) {};
        QueryResult eval(TextQuery &t) const override;
        string rep() const override {
            return word;
        };
        string word;
};

class Query {
    friend Query operator|(const Query &l, const Query &r);
    friend Query operator&(const Query &l, const Query &r);
    friend Query operator~(const Query &q);
    public:
        Query(const string &s) {
            p = shared_ptr<Query_base>(new WordQuery(s));
        }
        QueryResult eval(TextQuery &t) const {
            return p->eval(t);
        }
        string rep() const {
            return p->rep();
        }
    private:
        Query(shared_ptr<Query_base> base) : p(base) {};
        shared_ptr<Query_base> p;
};

class NotQuery : public Query_base {
    friend Query operator~(const Query &q);
    private:
        NotQuery(const Query & in_q) : q(in_q) {};
        QueryResult eval(TextQuery &t) const override;
        string rep() const override {
            return "~(" + q.rep() + ")";
        };

        Query q;
};

class BinaryQuery : public Query_base {
    protected:
        BinaryQuery(const Query &in_l, const Query &in_r, string in_symbol) : \
            l(in_l), r(in_r), symbol(in_symbol) {};
        string rep() const override {
            return "(" + l.rep() + " " + symbol + " " + r.rep() +")";
        };

        Query l, r;
        string symbol;
};

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query &in_l, const Query &in_r);
    private:
        AndQuery(const Query &in_l, const Query &in_r) : BinaryQuery(in_l, in_r, "&") {};
        QueryResult eval(TextQuery &t) const override;
};

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query &in_l, const Query &in_r);
    private:
        OrQuery(const Query &in_l, const Query &in_r) : BinaryQuery(in_l, in_r, "|") {};
        QueryResult eval(TextQuery &t) const override;
};
#endif
