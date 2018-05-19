//
// Created by slawek on 15.05.18.
//

#include <set>
#include <map>
#include <vector>
#include "Algo.h"

namespace algo {
//1
    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {
        out->resize(n_elements);

        copy_n(v.begin(), 7, out->begin());
    }
//2
    bool Contains(const std::vector<int> &v, int element) {
        return std::binary_search(v.begin(), v.end(), element);
    }
//3
    void InitializeWith(int initial_value, std::vector<int> *v) {
        std::fill(v->begin(), v->end(), initial_value);
    }
//4
    std::vector<int> InitializedVectorOfLength(int length, int initial_value) {
        vector<int> v;
        v.resize(length);
        std::fill(v.begin(), v.end(), initial_value);

        return v;
    }
//5
    std::vector<std::string> MapToString(const std::vector<double> &v) {
        vector<string> vStr;
        vStr.resize(v.size());

        std::transform(v.begin(),
                       v.end(),
                       vStr.begin(),
                       [](double d) { return std::to_string(d); }
        );

        return vStr;
    }

    std::set<string> Keys(const std::map<string, int> &m) {
        //std::set<string> setStr;
        //std::transform()

        //return setStr;
    }

    bool ContainsKey(const std::map<string, int> &v, const std::string &key) {
        return v.find(key) != v.end();
    }

    std::vector<int> Values(const std::map<string, int> &m) {
        return vector<int>();
    }

    bool ContainsValue(const std::map<string, int> &v, int value) {
        return ;
    }

}