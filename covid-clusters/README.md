
# COVID-19 Clusters

With the loosening of circuit breaker measures, new cases and clusters are expected to form. Thankfully (or unfortunately), each person is embedded with a contact tracing chip that records people they had contact with. With this technology in place, you are tasked to develop a program that lists the clusters given the seeding infections.

#### Inputs:
The first line of the input contains an integer `n`, the number of people in the population.
The second line of the input contains information on the seeding infections, starting with an integer `m` -- the number of seeding infections, followed by a space-separated list of `m` people who are initially infected.
The next `n` lines contains the number of contacts each person had, along with the list of people they had contact with.

Each person is represented uniquely by an integer from `1` to `n`.

#### Outputs:
Print the number of clusters and the size of each cluster


#### Example:
Attempt to draw the contacts in text, persons 1, 5 and 8 are the seed infections.
```
(1)--2

3--4--(5)

 6---7
 |   |
(8)--9
```


#### Input
```
9
3 1 5 8
1 2
1 1
1 4
2 3 5
1 4
2 7 8
2 6 9
2 6 9
2 7 8
```

#### Output
3 clusters formed with sizes 2, 3 and 4.
```
3
2 3 4
```
