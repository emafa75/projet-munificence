
#include "market.h"

static struct market market = {};
static struct available_tokens available_tokens;  


void init_market(unsigned int seed)
{
	printf("%d\n", seed);
	for (enum color_t color = 0 ; color < NUM_TOKENS / TOKENS_PER_COLOR ; ++color)
	{
		for (int j = 0 ; j < TOKENS_PER_COLOR ; ++j)
		{
			market.tokens[color * TOKENS_PER_COLOR + j] = create_simple_token(color);
			available_tokens.available[color * TOKENS_PER_COLOR + j] = 1;
		}
	}
}


struct token_t * pick_token(int index)
{
	if (available_tokens.available[index] == 0)
		return NULL;

	return &market.tokens[index];
}


void pay_token(struct token_t * token)
{
	for (int i = 0 ; i < NUM_TOKENS ; ++i)
	{
		if (&market.tokens[i] == token)
		{
			available_tokens.available[i] = 1;
			return;
		}
	}
}


struct available_tokens *get_available_tokens()
{
	return &available_tokens;
}





