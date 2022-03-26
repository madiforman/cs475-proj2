/* ready.c - ready */

#include <xinu.h>

struct queue *readyqueue; /** ready queue */

/**
 * Put process on ready queue
 * @param pid	ID of process to place on ready queue
 * @param resch	reschedule afterward?
 */
status ready(pid32 pid, bool8 resch)
{
	register struct procent *prptr;

	if (isbadpid(pid))
		return (SYSERR);

	// set process state to indicate ready and add to ready list
	prptr = &proctab[pid];

	// TODO - set the process' state pointed by prptr to "ready"
	prptr->prstate = PR_READY; // DC REMOVE

	// TODO - enqueue the process
	enqueue(pid, readyqueue, prptr->prprio); // DC REMOVE

	if (AGING && (readyqueue->size > 1))
	{
		printqueue(readyqueue);
		age(readyqueue);
		printqueue(readyqueue);
	}
	if (resch == RESCHED_YES)
		resched();

	return OK;
}
/**
 * @brief each process in the ready q will have its priority increased by 1,
 * and the lowest priority prc will be multiplied by 2
 *
 * @param q
 */
void age(struct queue *q)
{
	struct qentry *t = q->tail->prev;
	if (t->pid != 0 && t != NULL)
	{
		kprintf("starting\n");
		pri16 p = t->priority + 1;
		pid32 pid = remove(t->pid, q);
		enqueue(pid, q, p);
	}
}
