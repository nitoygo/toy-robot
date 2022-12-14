#pragma once

#include <string>
#include <unordered_map>
#include <initializer_list>


class QueryResponse {

public:
    explicit QueryResponse(std::initializer_list<std::pair<const std::string, std::string>> data) :
        data_(data) {}

    void AddData(std::initializer_list<std::pair<const std::string, std::string>> data) {
        data_.insert(data);
    }

    void AddData(std::string key, const std::string &value) {
        data_[key] = value;
    }

    const std::string& GetData(std::string key) const {
        return data_.at(key);
    }

protected:
    std::unordered_map<std::string, std::string> data_;
};
