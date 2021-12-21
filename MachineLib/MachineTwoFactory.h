/**
 * @file MachineTwoFactory.h
 * @author Noah O'Bryan
 *
 * Factory that builds the Second Machine
 */

#ifndef CANADIANEXPERIENCE_MACHINETWOFACTORY_H
#define CANADIANEXPERIENCE_MACHINETWOFACTORY_H

/// Forward reference to the ActualMachine class
class ActualMachine;

/**
 * Factory that builds the second machine
 */
class MachineTwoFactory {
private:

public:
    std::shared_ptr<ActualMachine> Create(std::wstring imagesDir);
};

#endif //CANADIANEXPERIENCE_MACHINETWOFACTORY_H
