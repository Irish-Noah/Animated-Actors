/**
 * @file MachineOneFactory.h
 * @author Noah O'Bryan
 *
 * Factory that builds the first machine
 */

#ifndef CANADIANEXPERIENCE_MACHINEONEFACTORY_H
#define CANADIANEXPERIENCE_MACHINEONEFACTORY_H

/// Forward reference to the ActualMachine class
class ActualMachine;

/**
 * Factory that builds machine one
 */
class MachineOneFactory {
private:

public:
    std::shared_ptr<ActualMachine> Create(std::wstring imagesDir);
};

#endif //CANADIANEXPERIENCE_MACHINEONEFACTORY_H
