/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "CellImpl.h"

Cell::Cell(CellCoord const& p)
{
    data.Part.grid_x = p.x_coord / MAX_NUMBER_OF_CELLS;
    data.Part.grid_y = p.y_coord / MAX_NUMBER_OF_CELLS;
    data.Part.cell_x = p.x_coord % MAX_NUMBER_OF_CELLS;
    data.Part.cell_y = p.y_coord % MAX_NUMBER_OF_CELLS;
    data.Part.nocreate = 0;
    data.Part.reserved = 0;
}

Cell::Cell(float x, float y)
{
    CellCoord p = Trinity::ComputeCellCoord(x, y);
    data.Part.grid_x = p.x_coord / MAX_NUMBER_OF_CELLS;
    data.Part.grid_y = p.y_coord / MAX_NUMBER_OF_CELLS;
    data.Part.cell_x = p.x_coord % MAX_NUMBER_OF_CELLS;
    data.Part.cell_y = p.y_coord % MAX_NUMBER_OF_CELLS;
    data.Part.nocreate = 0;
    data.Part.reserved = 0;
}
