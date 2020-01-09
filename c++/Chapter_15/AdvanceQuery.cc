#include "AdvanceQuery.h"
#include <algorithm>
#include <iterator>

using namespace std;

Query operator~(const Query &in_q) {
    return shared_ptr<Query_base> (new NotQuery(in_q));
}

Query operator&(const Query &in_l, const Query &in_r) {
    return shared_ptr<Query_base> (new AndQuery(in_l, in_r));
}

Query operator|(const Query &in_l, const Query &in_r) {
    return shared_ptr<Query_base> (new OrQuery(in_l, in_r));
}

QueryResult WordQuery::eval(TextQuery &t) const {
    return t.query(word);
}

QueryResult NotQuery::eval(TextQuery &t) const {
    auto notTmp = q.eval(t);
    set<line_no> result;
    line_no sz = notTmp.getfile()->size();
    auto beg = notTmp.begin();
    auto end = notTmp.end();

    for(line_no index = 0; index != sz; ++index) {
        if (beg == end || *beg != index)
            result.insert(index);
        else if(beg != end)
            ++beg;
    }
    return QueryResult(notTmp.getfile(), rep(), result);
}

QueryResult AndQuery::eval(TextQuery &t) const {
    auto leftTmp = l.eval(t);
    auto rightTmp = r.eval(t);
    set<line_no> result;

    set_intersection(leftTmp.begin(), leftTmp.end(), \
            rightTmp.begin(), rightTmp.end(), inserter(result, result.begin()));

    return QueryResult(leftTmp.getfile(), rep(), result);
}

QueryResult OrQuery::eval(TextQuery &t) const {
    auto leftTmp = l.eval(t);
    auto rightTmp = r.eval(t);
    set<line_no> result(leftTmp.begin(), leftTmp.end());

    for(auto beg = rightTmp.begin(); beg != rightTmp.end(); ++beg) {
        result.insert(*beg);
    }

    return QueryResult(leftTmp.getfile(), rep(), result);
}
