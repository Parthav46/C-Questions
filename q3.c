/**
Vulture and  Eagle are on a scavenger hunt you have devised.
They are going to visit a set of locations and you are going to leave exactly one
object at each location. There are precisely two different types of objects, say
type A and type B. Futhermore, Vulture only likes objects of type A and Eagle
only likes objects of type B so Vulture will never collect a type B object and
Eagle will never collect a type A object.
Vulture and Eagle will travel together and visit these locations one at a time.
If at any point during their journey one person has many more of their preferred
item than the other, then the other will get jealous and they may fight. To help
avoid such fights, you want to assign items to locations to minimize the maximum
difference between the number if items they hold over the whole journey.
Specifically, if R = (r1,r2,...,rn) is the order the locations will be visited
and P is an assignment of an object to each location, then we define dR(P,t) to
be the difference between the number of objects Vulture has and the number of objects
 Eagle has after visiting the first t locations. Finally, let dR(P) denote the maximum
  of dR(P,t) over all times t. The goal would be to find an assignment P to minimize dR(P).

Both Vulture and Eagle have decided on an order they want to visit the items.
Vulture wants to follow order S but Eagle wants to follow order T. It looks like
they are a long way from resolving this dispute but you need to place the items now!
To minimize the effect of the worst-case scenario, you want to place the items in some
manner P to minimize the maximum of dS(P) and dT(P).
*/
