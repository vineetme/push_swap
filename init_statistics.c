#include "push_swap.h"

void	init_statistics(t_statistics *stats)
{
	stats->disorder = 0.0;
	stats->total_ops = 0;
	stats->sa_count = 0;
	stats->sb_count = 0;
	stats->ss_count = 0;
	stats->pa_count = 0;
	stats->pb_count = 0;
	stats->ra_count = 0;
	stats->rb_count = 0;
	stats->rr_count = 0;
	stats->rra_count = 0;
	stats->rrb_count = 0;
	stats->rrr_count = 0;
	stats->silent = 0;
	stats->strategy_name = NULL;
	stats->complexity_class = NULL;
}
