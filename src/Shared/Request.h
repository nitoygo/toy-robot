#pragma once

#include <string>
#include <unordered_map>

class Request
{
public:
    Request() = default;
    Request(std::string name) : name_(name) {}

    std::string GetName() const { return name_; }

    Request& WithName(std::string name) {
        name_ = name;
        return *this;
    }

    Request& WithParameter(std::string key, const std::string &value) {
        parameters_[key] = value;
        return *this;
    }

    void AddParameter(std::string key, const std::string &value) {
        parameters_[key] = value;
    }

    void AddParameters(std::initializer_list<std::pair<const std::string, std::string>> parameters) {
        parameters_.insert(parameters);
    }

    const std::string& GetParameter(std::string key) const {
        return parameters_.at(key);
    }

    int GetParameterAsInt(std::string key) const {
        return std::stoi(GetParameter(key));
    }

protected:
    std::string name_;
    std::unordered_map<std::string, std::string> parameters_;

};
