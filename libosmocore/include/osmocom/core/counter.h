#pragma once

/*! \file counter.h
 *  Common routines regarding counter handling */

/*! Structure representing a single counter */
struct osmo_counter {
	struct llist_head list;		/*!< internal list head */
	const char *name;		/*!< human-readable name */
	const char *description;	/*!< humn-readable description */
	unsigned long value;		/*!< current value */
	unsigned long previous;		/*!< previous value */
};

/*! Decrement given counter by one
 *  \param[in] ctr Counter that's to be decremented */
static inline void osmo_counter_dec(struct osmo_counter *ctr)
{
	ctr->value--;
}

/*! Increment counter by one.
 *  \param[in] Counter that's to be incremented */
static inline void osmo_counter_inc(struct osmo_counter *ctr)
{
	ctr->value++;
}

/*! Get current value of counter */
static inline unsigned long osmo_counter_get(struct osmo_counter *ctr)
{
	return ctr->value;
}

/*! Reset current value of counter to 0 */
static inline void osmo_counter_reset(struct osmo_counter *ctr)
{
	ctr->value = 0;
}

struct osmo_counter *osmo_counter_alloc(const char *name);

void osmo_counter_free(struct osmo_counter *ctr);

int osmo_counters_for_each(int (*handle_counter)(struct osmo_counter *, void *), void *data);

int osmo_counters_count();

struct osmo_counter *osmo_counter_get_by_name(const char *name);

int osmo_counter_difference(struct osmo_counter *ctr);
