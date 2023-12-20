#pragma once
#include<iostream>
#include<random>

#define Technique 1 //术法
#define Ritual 0 //仪式
#define Orgin 2 //本源
#define Realistic 1 //现实
#define Mental 0 //精神
#define Tree 0 //木
#define Animal 1 //兽
#define Stone 2 //岩
#define Star 3 //星
#define	Quick 7 //灵
#define Wisdom 17 //智

#define Sum_property 19

using namespace std;

typedef struct __property {
	float npc_property = 0; //角色系 0
	float attack = 0; //攻击 1
	float life = 0; //生命上限 2
	float realistic_defense = 0; //现实防御 3
	float mental_defense = 0; //精神防御 4 
	float penetration_rate = 0; //穿透率 5
	float critical_chance = 0; //暴击率 注：应该设成小数 6
	float crit_damage = 0; //暴击创伤 注：应该设成小数 7
	float crit_resist_rate = 0; //抗暴率 注：应该设成小数 8
	float crit_defense = 0; //暴击防御 注：应该设成小数 9
	float trauma_addition = 0; //创伤加成 10
	float trauma_relief = 0; //受创减免 11
	float power_technique = 0; //术法威力 12
	float power_ritual = 0; //仪式威力 13
	float treatment_rate = 0; //治疗率 14
	float untreatment_rate = 0; //减疗率 15
	float leech_rate = 0; //吸血率 16
	float trauma_recovery = 0; //受创回复 17
	float power_orgin = 0; //本源伤害加成 18
	/*struct __property copy()
	{
		struct __property a;
		a.npc_property = npc_property;
		a.attack = attack;
		a.life = life;
		a.realistic_defense = realistic_defense;
		a.mental_defense = mental_defense;
		a.penetration_rate = penetration_rate;
		a.critical_chance = critical_chance;
		a.crit_damage = crit_damage;
		a.crit_resist_rate = crit_resist_rate;
		a.crit_defense = crit_defense;
		a.trauma_addition = trauma_addition;
		a.trauma_relief = trauma_relief;
		a.power_technique = power_technique;
		a.power_ritual = power_ritual;
		a.treatment_rate = treatment_rate;
		a.untreatment_rate = untreatment_rate;
		a.leech_rate = leech_rate;
		a.trauma_recovery = trauma_recovery;
		a.power_orgin = power_orgin;
		return a;
	}*/
}property;

union fproperty {
	property fpropertys;
	float p[Sum_property];
	fproperty(property __fproperty) { fpropertys = __fproperty; };
};

typedef struct __buff {
	int sum; //层数
	int id; //格式为三位以上小数，后面俩位用于标记作用的属性
	void (*p)(); //特殊效果函数，请使用全局变量中的当前伤害者和被伤害者确定使用者和被使用者
}buff;



//typedef struct __card {
//	string name; //卡牌名字
//	void (*p)(NPC); //卡牌效果指针
//}card;
