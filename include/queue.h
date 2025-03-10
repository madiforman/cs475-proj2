/* queue.h */

/* Queue structure declarations, constants, and inline functions	*/

/* Default # of queue entries: 1 per process plus 2 for ready list plus	*/
/*			2 for sleep list plus 2 per semaphore		*/

#ifndef NQENT
#define NQENT (NPROC + 4 + NSEM + NSEM)
#endif

#define EMPTY (-1) /* null value for qnext or qprev index	*/

// TODO - define queue's data members
struct queue
{
	struct qentry *head; // TODO - pointer to head qentry
	struct qentry *tail; // TODO - pointer to tail qentry
	int32 size;			 // TODO - size of queue
};

// TODO - define a queue entry's data members
struct qentry
{
	pid32 pid;			 // TODO - process ID
	struct qentry *next; // TODO - other members
	struct qentry *prev;
	int32 priority;
};

/* Queue function prototypes (don't touch!) */
void printqueue(struct queue *q);

bool8 isempty(struct queue *q);
bool8 nonempty(struct queue *q);
bool8 isfull(struct queue *q);

pid32 getfirst(struct queue *q);
pid32 getlast(struct queue *q);
pid32 remove(pid32 pid, struct queue *q);
pid32 dequeue(struct queue *q);
pid32 enqueue(pid32 pid, struct queue *q, int32 key);
struct queue *newqueue();
struct qentry *getbypid(pid32 pid, struct queue *q);
