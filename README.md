# SkittleBags
Title: Final project and presentation

Due date for code submission: TBD

Code competition / presentation: TBD

Description:
Your final project will be writing code optimized for parallel organizations and architectures. Your team of two will compete against three other teams in a final showdown at the end of the semester. You will also present your code to the class.
Your choice is between writing for OpenMP or MPI. We practiced writing parallelized code in C; if you are more comfortable, you may also write this code in Fortran or Python.

Computing Options
You will do your code development on your iMacs and home computers. However, for the student competition, some of you will be given access to even better hardware.
If you use OpenMP, you will given access to a multicore machine of 12 processors or better for the student competition.
If you use MPI, you will be given access to a cluster of at least 2 nodes of 8 processors or more for the student competition. That is, you will have access to more processors than those using OpenMP, but the memory will not be shared between all processors.

Project Choices (each of these topics will be selected by four groups of two).

	1.	Crack a public/private key pair. After reading this forum answer (Links to an external site.) Links to an external site.  describing the importance of prime numbers in cryptography, write a parallel program to factorize a large multiple of two prime numbers. The program should take an large number as input, and output its two prime factors.
	◦	Your code submission will be graded by me on code clarity through comments, choice of method, and functionality.
	◦	For the student competition, you will be given several large numbers to factor (all numbers will be < 2 32    ). First team to accurately factor all of the numbers (or to factor the most prime numbers) wins.

	2.	Write a parallel program that, through simulation, estimates the average number of 2.17-oz bags of Skittles that need to be opened before running across two matching bags. Assume that there are five flavors of Skittles: red, orange, yellow, green, and purple. Assume that each bag of Skittles contains exactly 60 Skittles. Assume the color of each Skittle in the bag is independently and randomly assigned from the five choices (read the below links for more explanation of this concept). The program should generate/open bags of Skittles until it finds two matching bags, then start over. Your program should print a continually updated best-estimate of the average number of bags that need to be opened. The estimate will get better and better the more bags are opened. Here are two blog posts by a mathematician that inspired this assignment: a math post (Links to an external site.) Links to an external site.  and a follow-up experiment post (Links to an external site.) Links to an external site. . 
	◦	Your code submission will be graded by me on code clarity through comments, choice of method, and functionality.
	◦	For the student competition, you will be given a fixed amount of time to run your simulation. The team with the most accurate answer at the end of this time period wins.

	3.	Implement a casino game (e.g. blackjack, roulette, etc.) where one processor/thread is the "dealer" and the others are "clients." Each client should keep track of its own money, and make its own play decisions.
	◦	Your code submission will be graded by me on code clarity through comments, creativity, choice of method, and functionality.
	◦	For the student competition, you will be judged by vote regarding the most creative and impressive implementation. You will need to show your code running to the class. The team with the most votes wins.

Commenting:
Use comments liberally throughout your work. Every section of your code should be well explained through comments. At each stage, your comments should answer the questions: 1) What am I doing here?, and 2) Why am I doing it? You should also have a comment in the header, giving authorship, dates, and a detailed summary of the method implemented in your code.

Submission:
Submit your final code, an illustrative screenshot of your code running, and your presentation slides to CI Learn.
