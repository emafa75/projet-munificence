#include "guild.h"
#include "builder.h"
#include "market.h"
#include "stack/stack.h"
#include <stdio.h>


static struct guild guild;
void init_guild()
{
    guild.n_builders = num_builders();
    for (int index = 0; index < guild.n_builders; ++index)
    {
        guild.builders[index] = make_builder(index);

				stack_append(&guild.available_stack, &guild.builders[index]);
    }
    
}


int guild_nb_builder()
{
    return guild.n_builders;
}

void guild_display()
{
    struct available_builders available_builders = {};
		available_builders.n_builders_available = stack_get_values(&guild.available_stack, available_builders.available, MAX_BUILDERS * sizeof(struct builder_t *));

    for (unsigned int index = 0 ; index < available_builders.n_builders_available ; ++index)
    {
			// printf("%d: %d\n", i, builder_level(available_builders.available[index]));
			builder_display(available_builders.available[index], " --- ");
    }
}


struct builder_t* guild_pick_builder()
{
		struct builder_t * builder = stack_pop(&guild.available_stack);
		guild.n_builders--;
    return builder;
}


void guild_put_builder(struct builder_t * builder)
{
	stack_append(&guild.available_stack, builder);
}


struct available_builders get_available_builders()
{
    struct available_builders available_builders = {};
		available_builders.n_builders_available = stack_get_values(&guild.available_stack, available_builders.available, MAX_BUILDERS * sizeof(struct builder_t *));

    return available_builders;
}

// int get_first_available_builder(int i)
// {
//
//     struct available_builders available_builders = get_available_builders();
//     for (int index = i; index < MAX_BUILDERS; ++index) {
//         if (available_builders.available[index])
//         {
//             return index;
//         }
//     }
//     return -1;
// }


