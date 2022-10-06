#pragma once

#include <string>
#include <unordered_map>


enum class ResponseCode {
    kSuccess = 0,
    kGeneralError = -1,
    kInvalidParameterError = -2
};


class Response
{
public:
    Response() = default;
    Response(ResponseCode code) : code_(code) {}

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
    ResponseCode code_;
    std::unordered_map<std::string, std::string> data_;
};
