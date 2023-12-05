#ifndef __SKILLS_H__
#define  __SKILLS_H__

#include "builder.h"
#include "game.h"
#include "skills_tokens.h"
#include "skills_builders.h"

#define MAX_SKILLS_PER_TRIGGER 3
#define NB_SKILLS_IN_GAME (MAX_BUILDERS + NUM_TOKENS)


typedef int (*skill_f)(struct turn_t* , const void* );



enum skills_id{
    NO_SKILL,
    TOKEN_ROB,
    TURN_ROB,
    MASTERS_HAND,
    MARKET_PANIC,
    GUILD_PANIC,
    BUILDER_FIRST_SKILL = TOKEN_ROB,
    BUILDER_LAST_SKILL = MASTERS_HAND,
    TOKEN_FIRST_SKILL = MARKET_PANIC,
    TOKEN_LAST_SKILL = GUILD_PANIC,
    NUM_SKILLS = TOKEN_LAST_SKILL + 1
};

struct skill_instance_t{
    void*  trigger;
    enum skills_id skills[MAX_SKILLS_PER_TRIGGER];
};


/*
    Add skills associate to a trigger, if the trigger exist replace the skills by new one
*/
void add_skill_instance(void* trigger, enum skills_id skills[MAX_SKILLS_PER_TRIGGER]);

/*
    Returns the array of the all the skills for a specific pointer
*/
enum skills_id* skills_get_by_trigger(const void* trigger);

/*
    Check if a trigger has already skills associated and return the index in associated_skill array
*/
int is_associate_to_a_skill(const void* trigger);
/*
    Check if a trigger has skills (non null)
*/
int has_skills(const void* trigger);

/*
    Return skill_f for a specific skill id
*/
skill_f skill_by_id(enum skills_id skill);


/*
    Display the skill with skill id
*/
void skill_display(enum skills_id skill, char* prefix);


/*
    Execute skills associate to a trigger
*/
void skill_exec(struct turn_t* turn, const void* trigger);

/*
	Display skills execute by a trigger
*/
void trigger_display_skill(const void* trigger);
#endif
