
#include "favors.h"
#include "game.h"
#include "market.h"
#include "players.h"
#include "skills.h"
#include "token.h"
#include <stdlib.h>
#include "builder_constants.h"


skill_f favors_functions[NUM_SKILLS] = {
	NULL,
	favor_return,
	favor_renewal
};


char *favors_strings[NUM_SKILLS] = {
	"no favors",
	"favor_return",
	"favor_renewal",
};


int favor_return(struct turn_t *turn, const void *trigger)
{
	UNUSED(trigger);

	struct market_t* global_market = turn_get_market(turn);
	struct player_t* current_player = turn_get_current_player(turn);
	struct token_t* taken_token;

	// Get the index of a random token in global_market
	int token_ind = market_get_linked_tokens(global_market, 1);

	if (token_ind == -1)
		return 0;

	taken_token = global_market->tokens[token_ind];

	player_pick_token(global_market, current_player, taken_token);
	return 1;
}

int favor_renewal(struct turn_t* turn, const void* trigger)
{
	UNUSED(trigger);
	/*
		Get turn instances
	*/
	struct guild_t* game_guild = turn_get_guild(turn);

	/*
		Choose a random level to renew
	*/
	unsigned int renewed_level = rand() % NUM_LEVELS;

	/*
		Get all the builder with this level wich are available
	*/

	struct available_builders* available_builders = guild_get_available_builders(game_guild);

	struct builder_t* builders[MAX_BUILDERS_AVAILABLE_PER_LVL] = {};
	int index_b = 0;

	for (int index = 0; index < MAX_BUILDERS; ++index)
	{
		struct builder_t* builder = available_builders->builders[index];
		unsigned int builder_lvl = builder_level(builder);
		if (builder_lvl == renewed_level)
		{
			builders[index_b] = builder;
			++index_b;
		}
	}

	/*
		Remove them from the guild and replace it in the queue
	*/

	for (int index = 0; index < MAX_BUILDERS_AVAILABLE_PER_LVL; ++index)
	{
		guild_pick_builder(game_guild, builders[index]);
		guild_put_builder(game_guild, builders[index]);
	}

	return 1;
}
