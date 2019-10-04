/**
Zombie Land.

Two Zombie hunters,Wastson and Patrick are on a mission to clear the rave party land.
Their goal is to kill all the zombies out there. A certain number of points is given
for killing each zomnie depending on the type of zombie and their strength factor.

There are n types of Zombies. The number of zombies of type ai and zombie cost ci
is known for each type. A hunter gets ci.f points for destroying one zombie of type
i, where f is the strength factor. The stregth factor can be an integer number from
1 to t + 1, inclusive. At the beginning of the game the factor value is equal to 1.
The factor is set to i + 1 after destruction of pi (1 <= i <= t) zombies, so the
(pi + 1)-th zombie to be killed is considered with factor equal to i+1.

Your task is to determine the maximum number of points Watson and Patrick can get
after they kill all the zombies. Take into account that they are so tough that
they can kill zombies in any order chosen by them individually.
*/
