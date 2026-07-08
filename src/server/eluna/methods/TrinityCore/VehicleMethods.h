/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <https://elunaluaengine.github.io/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef VEHICLEMETHODS_H
#define VEHICLEMETHODS_H

/***
 * Inherits all methods from: none
 */
namespace LuaVehicle
{
    /**
     * Returns true if the [Unit] passenger is on board
     *
     * @param [Unit] passenger
     * @return bool isOnBoard
     */
    int IsOnBoard(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Vehicle]'s owner
     *
     * @return [Unit] owner
     */
    int GetOwner(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Vehicle]'s entry
     *
     * @return uint32 entry
     */
    int GetEntry(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Returns the [Vehicle]'s passenger in the specified seat
     *
     * @param int8 seat
     * @return [Unit] passenger
     */
    int GetPassenger(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Adds [Unit] passenger to a specified seat in the [Vehicle]
     *
     * @param [Unit] passenger
     * @param int8 seat
     */
    int AddPassenger(Eluna* /*E*/)
{
    return 1;
}

    /**
     * Removes [Unit] passenger from the [Vehicle]
     *
     * @param [Unit] passenger
     */
    int RemovePassenger(Eluna* /*E*/)
{
    return 1;
}
    
    ElunaRegister<Vehicle> VehicleMethods[] =
    {
        // Getters
        { "GetOwner", &LuaVehicle::GetOwner },
        { "GetEntry", &LuaVehicle::GetEntry },
        { "GetPassenger", &LuaVehicle::GetPassenger },

        // Boolean
        { "IsOnBoard", &LuaVehicle::IsOnBoard },

        // Other
        { "AddPassenger", &LuaVehicle::AddPassenger },
        { "RemovePassenger", &LuaVehicle::RemovePassenger }
    };
}

#endif // VEHICLEMETHODS_H
