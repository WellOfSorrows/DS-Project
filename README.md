# Data Structures & Algorithms Project
This is the final project of the "Data Structures & Algorithms" course, instructed by [Dr. Hossein Esfandiari](https://sites.google.com/view/hossein-esfandiari) in the spring semester of 2021 at Shiraz University.

# Description
The goal of this project is to develop a system that maintains and processes patients’ information. For each patient we have a unique patient ID which is a positive integer (between 0 and 10^9), and a health measure which is an integer (between -10^9 and 10^9). Design and implement a data structure that supports the following queries:

- Add X Y: This operation inserts a patient with patient ID X and health measure Y to the data structure. This operation is called upon the arrival of a patient.

- Serve First: This operation serves the patient in the data structure that arrived the earliest, and removes her from the dataset.

- Serve Sickest: This operation serves the patient in the data structure that has the lowest health measure and removes her from the dataset.

- Update X Y: This operation updates the health measure of the patient X to value Y.

The running time of each operation should be either O(log(n)) in the worst case, or O(1) in expectation. Note that you are supposed to implement any data structure that you need yourself. You are not allowed to use data structures from the standard library of your programming language or from the internet.
The input is a list of queries, with one query per line. Whenever a patient is served (either through Serve First or Serve Sickest), write the patient’s ID followed by a space and the patient's health measure at the serving time, and move to the next line.
The queries are set such that the number of patients in the data structure is always less than or equal to 10^6. However, the total number of patients that are inserted to the data structure and served is not limited.

# Implementation

The data structures used in this project is as follows:
- A quasi-queue (implemented via a doubly linked-list) used to govern the patients and congregate them in one place.
- A quasi-queue (implemented via a doubly linked-list) used to keep track of the patients' entry order.
- An AVL tree used to sort patients by their health measure.
- An AVL tree used to sort patients by their ID.

**Keep in mind that since structures are implemented using linked-lists, and not arrays, thus there is no limit for the number of patients.**

Suppose each patient is an instance of a structure named "Composite Entity" or "EntityC" for short. Each EntityC node three sub-structures:
- A node in the health measure AVL tree.
- A node in the ID AVL tree.
- A node in the entry order queue.

Since these nodes can be accessed from the complex node and vice versa, in other words they are bidirectionally linked, ergo we can go from one structures to another in constant time.

Here is a visualized representation of the project implementation (to simplify the picture, only the complete relations of a single node is shown):
<p align="center">
  <img src="https://github.com/WellOfSorrows/DS-Project/blob/main/implementation.png?raw=true" alt="Implementation Image."/>
</p>
