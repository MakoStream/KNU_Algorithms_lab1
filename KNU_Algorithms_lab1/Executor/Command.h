#pragma once
#include <vector>
#include <string>


// Базовий клас для будь-якої команди
class Command {
public:
    virtual ~Command() = default;
    virtual void execute(const std::vector<std::string>& args) = 0; // чисто віртуальний метод
    virtual std::string name() const = 0; // ім'я команди
};