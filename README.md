# Seating-Problem-to-Avoid-Students-Cheating

This C++ algorithm seats a user specified number of students into a row of chairs that is a user specified length. It seats the students in a way that they are as far spread out as possible. The algorithm does not provide the perfect solution for every possible value, but is an alternate take on this problem. The row of chairs is depicted as an array, with 0s being empty seats and 1s being seats that are already seated.

This algorithm works by scanning through the row of chairs, and retrieving the details of the longest unseated segment. It determines the midpoint of this segment and places a student there. It then recursively calls itself as many times as needed to seat the correct amount of students.
