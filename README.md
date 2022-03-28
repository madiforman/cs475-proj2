# cs475-proj2

============================================================================
Name : Xinu Project 2
Authors : Clark Brace && Madison Sanchez-Forman
Version : 3.27.22
Description : Implements a priority queue for process scheduling. If
AGING in kernel.h is set to TRUE it will also implement an aging policy
to prevent starvation.
============================================================================
https://davidtchiu.github.io/teaching/cs475/proj2/

Our aging policy is in fact effective at preventing large processes with high priority from taking up all the CPU time and thus starving other lower-priority processes. Our tests show that despite the presence of large processes being in the queue, due to aging lower priority processes, will eventually gain higher and higher priority until they eclipse that of said large processes. This helps maintain a more balanced and fair processing order and prevents starvation. Our aging process also extends to negative priorities and will ensure that eventually they will also increase and thus also have a chance to run. Overall our aging policy removes the possibility of starvation by constantly increasing the priority of processes that have not had the opportunity to run.
