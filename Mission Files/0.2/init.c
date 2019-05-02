	//Spawn helper function
void SpawnObject(string objectName, vector position, vector orientation)
{
    Object obj;
    obj = Object.Cast(GetGame().CreateObject(objectName, "0 0 0"));
    obj.SetPosition(position);
    obj.SetOrientation(orientation);

    // Force update collisions
    if (obj.CanAffectPathgraph())
    {
        obj.SetAffectPathgraph(true, false);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
    }
}

void main()
{
	//Zelenogorsk Military
	SpawnObject("Land_Mil_Barracks2", "2493.202393 194.726913 5078.796387", "-31.000004 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks3", "2469.770020 195.414780 5104.504883", "-129.999939 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks2", "2541.591553 194.923004 5103.967773", "146.000015 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks_Round", "2389.748535 191.558044 5099.453613", "-101.000008 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks_Round", "2386.439453 191.466217 5120.461426", "-101.000008 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks_Round", "2500.164795 194.863998 5035.984375", "147.000031 0.000000 0.000000");
	SpawnObject("Land_Mil_Fortified_Nest_Watchtower", "2556.740967 192.546783 5199.595703", "167.000000 0.000000 0.000000");
	SpawnObject("Land_Wreck_Volha_Police", "2529.853516 194.932587 5027.924316", "0.000000 0.000000 0.000000");
	SpawnObject("Land_Wreck_Volha_Police", "2527.284668 194.642471 5039.973633", "0.000000 0.000000 0.000000");
	SpawnObject("Land_Wreck_Volha_Police", "2513.404297 194.716263 5031.275391", "-70.000000 0.000000 0.000000");
	SpawnObject("Land_Wreck_Volha_Police", "2511.732422 194.543839 5016.262207", "-32.000004 0.000000 0.000000");
	SpawnObject("Land_Mil_Tent_Big2_1", "2492.294678 195.198105 5126.408691", "45.999996 0.000000 0.000000");
	SpawnObject("Land_Mil_GuardTower", "2486.469482 199.495529 5131.694336", "-174.000015 0.000000 0.000000");
	SpawnObject("Land_Mil_GuardTower", "2445.203125 199.441391 5126.074707", "143.000046 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks_Round", "2409.203613 191.336761 5159.751953", "-101.000008 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks_Round", "2509.374512 194.380157 5140.915527", "-9.000003 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks_Round", "2583.420410 194.590317 5134.860840", "51.000000 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks2", "2399.541504 191.645767 5080.270020", "48.000004 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks_Round", "2441.702148 191.683090 5100.253418", "138.000015 0.000000 0.000000");
	SpawnObject("Land_Wreck_Volha_Police", "2574.720703 195.137421 5054.516602", "0.000000 0.000000 0.000000");
	SpawnObject("Land_Wreck_Volha_Police", "2581.695801 195.402924 5057.840820", "0.000000 0.000000 0.000000");
	SpawnObject("Land_Wreck_Volha_Police", "2614.601318 196.047134 5079.868164", "-74.000000 0.000000 0.000000");
	SpawnObject("Land_Wreck_Volha_Police", "2598.272217 195.747543 5067.916504", "-55.000000 0.000000 0.000000");
	SpawnObject("Land_Misc_DeerStand2", "2389.311523 212.062317 5500.719727", "-12.000016 0.000000 0.000000");
	SpawnObject("Land_Misc_DeerStand2", "2365.783203 211.717514 5493.359375", "-23.000013 0.000000 0.000000");
	SpawnObject("Land_Misc_DeerStand2", "2335.269287 212.787918 5489.078125", "0.000000 0.000000 0.000000");
	SpawnObject("Land_Misc_DeerStand2", "2267.477539 209.233032 5482.840820", "-23.000013 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks6", "2562.309570 190.677170 5303.044922", "0.000000 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks6", "2564.912109 190.410126 5270.601563", "-179.999985 0.000000 0.000000");
	SpawnObject("Land_Mil_Barracks_Round", "2439.742920 191.394089 5140.210938", "169.000000 0.000000 0.000000");
	SpawnObject("Land_Wreck_Uaz", "2536.022461 194.073181 5108.675781", "0.000000 0.000000 0.000000");
	SpawnObject("Land_Wreck_Uaz", "2485.884033 194.188248 5088.708984", "0.000000 0.000000 0.000000");

	//GetTesting().ExportProxyData("7500 0 7500", 10000);  //Centre of map, radius of how far to go out and find buildings
	
	//INIT WEATHER BEFORE ECONOMY INIT------------------------
	Weather weather = g_Game.GetWeather();

	weather.MissionWeather(false);    // false = use weather controller from Weather.c

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
	weather.GetRain().Set( 0, 0, 1);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

    if ((month == reset_month) && (day < reset_day))
    {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    }
    else
    {
        if ((month == reset_month + 1) && (day > reset_day))
        {
            GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
        }
        else
        {
            if ((month < reset_month) || (month > reset_month + 1))
            {
                GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
            }
        }
    }
}

class CustomMission: MissionServer
{	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemTop;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;
		
		itemTop = player.FindAttachmentBySlotName("Body");
		
		if ( itemTop )
		{
			itemEnt = itemTop.GetInventory().CreateInInventory("Rag");
			if ( Class.CastTo(itemBs, itemEnt ) )
				itemBs.SetQuantity(4);

			SetRandomHealth(itemEnt);
			
			itemEnt = itemTop.GetInventory().CreateInInventory("RoadFlare");
			SetRandomHealth(itemEnt);
			
			rand = Math.RandomFloatInclusive(0.0, 1.0);
			if ( rand < 0.35 )
				itemEnt = player.GetInventory().CreateInInventory("Apple");
			else if ( rand > 0.65 )
				itemEnt = player.GetInventory().CreateInInventory("Pear");
			else
				itemEnt = player.GetInventory().CreateInInventory("Plum");
		
			SetRandomHealth(itemEnt);
		}
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}