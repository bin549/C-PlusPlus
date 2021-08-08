#ifndef ABSTRACT_H
#define ABSTRACT_H

DirType Direction(CELL cell1, CELL cell2);
DirType Direction(COORDINATE coord1, COORDINATE coord2);
int Distance(COORDINATE coord1, COORDINATE coord2);
COORDINATE As_Coord(TARGET target);

class AbstractTypeClass;

class AbstractClass
{
public:
	RTTIType RTTI;
	int ID;

	COORDINATE Coord;

	int Height;

	unsigned IsActive : 1;

	unsigned IsRecentlyCreated : 1;

	AbstractClass(RTTIType rtti, int id) : RTTI(rtti), ID(id), Coord(0xFFFFFFFFL), Height(0){};
	AbstractClass(NoInitClass const &x) { x(); };
	virtual ~AbstractClass(void){};

	/*
		**	Query functions.
		*/
	virtual char const *Name(void) const { return (""); }
	virtual HousesType Owner(void) const { return HOUSE_NONE; };
	TARGET As_Target(void) const { return (Build_Target(RTTI, ID)); };
	RTTIType What_Am_I(void) const { return (RTTI); };

/*
		**	Scenario and debug support.
		*/
#ifdef CHEAT_KEYS
	virtual void Debug_Dump(MonoClass *mono) const;
#endif

	/*
		**	Coordinate query support functions.
		*/
	virtual COORDINATE Center_Coord(void) const { return Coord; };
	virtual COORDINATE Target_Coord(void) const { return Coord; };

	/*
		**	Coordinate inquiry functions. These are used for both display and
		**	combat purposes.
		*/
	DirType Direction(AbstractClass const *object) const { return ::Direction(Center_Coord(), object->Target_Coord()); };
	DirType Direction(COORDINATE coord) const { return ::Direction(Center_Coord(), coord); };
	DirType Direction(TARGET target) const { return ::Direction(Center_Coord(), As_Coord(target)); };
	DirType Direction(CELL cell) const { return ::Direction(Coord_Cell(Center_Coord()), cell); };
	int Distance(TARGET target) const;
	int Distance(COORDINATE coord) const { return ::Distance(Center_Coord(), coord); };
	int Distance(AbstractClass const *object) const { return ::Distance(Center_Coord(), object->Target_Coord()); };

	/*
		**	Object entry and exit from the game system.
		*/
	virtual MoveType Can_Enter_Cell(CELL, FacingType = FACING_NONE) const { return MOVE_OK; };

	/*
		**	AI.
		*/
	virtual void AI(void){};

	/*
		** Set the new recently created flag every time the active flag is set. ST - 8/19/2019 5:41PM
		*/
	void Set_Active(void)
	{
		IsActive = true;
		IsRecentlyCreated = true;
	}
};

#endif