#include <iostream>
#include <memory>

class Vehicle
{
protected:
    int fuelCapacity;

public:
    Vehicle() {}
    Vehicle(int fuelCapacity) : fuelCapacity(fuelCapacity) {}
    virtual ~Vehicle() {}
    virtual Vehicle *doClone() const = 0;
    std::unique_ptr<Vehicle> clone() const { return std::unique_ptr<Vehicle>(doClone()); }

    virtual void describe() const = 0;
};

template <typename Base, typename Derived>
class VehicleCloneableValueObject : public Base
{
public:
    using Base::Base;

    virtual Base *doClone() const override
    {
        return new Derived(static_cast<const Derived &>(*this));
    }
};

class Car : public VehicleCloneableValueObject<Vehicle, Car>
{
private:
    typedef VehicleCloneableValueObject<Vehicle, Car> BaseClass;

public:
    Car() {}
    Car(int fuelCapacity) : BaseClass(fuelCapacity) {}

    virtual void describe() const
    {
        std::cout << "I am a car" << std::endl;
    }
};

class Plane : public VehicleCloneableValueObject<Vehicle, Plane>
{
private:
    typedef VehicleCloneableValueObject<Vehicle, Plane> BaseClass;

protected:
    int wingSpan;

public:
    Plane() {}
    Plane(int fuelCapacity, int wingSpan) : BaseClass(fuelCapacity), wingSpan(wingSpan) {}

    virtual void describe() const
    {
        std::cout << "I am a plane" << std::endl;
    }
};

class FighterPlane : public VehicleCloneableValueObject<Plane, FighterPlane>
{
private:
    typedef VehicleCloneableValueObject<Plane, FighterPlane> BaseClass;

protected:
    int numberOfBombs;

public:
    FighterPlane() {}
    FighterPlane(int fuelCapacity, int wingSpan, int numberOfBombs)
        : BaseClass(fuelCapacity, wingSpan), numberOfBombs(numberOfBombs) {}

    virtual void describe() const
    {
        std::cout << "I am a fighter plane" << std::endl;
    }
};