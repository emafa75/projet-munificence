#include "skills.h"
#include <stdio.h>

struct skill_instance_t associated_skills[NB_SKILLS_IN_GAME] = {}; 

skill_f skills_functions[NUM_SKILLS] = {
    NULL,
    token_rob,
    turn_rob,
    skill_masters_hand,
    market_panic,
    guild_panic,
};


char *skills_strings[NUM_SKILLS] = {
    "no skill",
	"token_rob",
	"turn_rob",
	"masters_hand",
    "market_panic",
	"guild_panic"
};


void add_skill_instance(void* trigger, enum skills_id skills_to_add[MAX_SKILLS_PER_TRIGGER])
{
    int index_skill = is_associate_to_a_skill(trigger);
    if(index_skill >= 0) //the trigger has already associated skills
    {
       for (int index = 0; index < MAX_SKILLS_PER_TRIGGER; ++index)
       {
            associated_skills[index_skill].skills[index] = skills_to_add[index];
       }
       return;
    }else {
        /*
            Find a place to place new skill instance
        */
        for (int index = 0; index < NB_SKILLS_IN_GAME; ++index)
        {
            if (associated_skills[index].trigger == NULL)
            {
                
                associated_skills[index].trigger = trigger;
                for (int skill_index = 0; skill_index < MAX_SKILLS_PER_TRIGGER; ++skill_index)
                {
                   associated_skills[index].skills[skill_index] = skills_to_add[skill_index];
                }
                return;
            }
        }
    }

}

int is_associate_to_a_skill(const void* trigger)
{
    for (int index = 0; index < NB_SKILLS_IN_GAME; ++index)
    {
        if(associated_skills[index].trigger == trigger && trigger != NULL)
        {
            return index;            
        }

    }
    return -1;
}

enum skills_id* skills_get_by_trigger(const void* trigger){
    int index_skill = is_associate_to_a_skill(trigger);

    if (index_skill < 0 )
    {
        return NULL;
    }
    return associated_skills[index_skill].skills;
}

skill_f skill_by_id(enum skills_id skill)
{
    return skills_functions[skill];
}


void skill_display(enum skills_id skill, char* prefix)
{
	printf("%s%s", prefix, skills_strings[skill]);
}

int has_skills(const void *trigger)
{
    int skill_instance_index = is_associate_to_a_skill(trigger);
    if (skill_instance_index < 0)
    {
        return 0;
    }
    if (associated_skills[skill_instance_index].skills[0] != NO_SKILL) //check if the first associated skill is a real skill
    {
        return 1;
    }
    return 0;
}