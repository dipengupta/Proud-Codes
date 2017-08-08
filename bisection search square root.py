# this is finding the (closest) square root of a number using bisection search.

x=250
epsilon=0.01
guesses=0
low=1.0
high=x
ans=(low+high)/2.0

while abs(ans**2 - x) >= epsilon :
    print ('low = ' + str(low) + ' high = ' + str(high) + ' ans = ' + str(ans))
    guesses+=1

    if ans**2 < x :
        low=ans
    else :
        high=ans

    ans=(low+high)/2.0

print('No. of Guesses = ' + str(guesses))
print(str(ans) + " is close to square root of " + str(x))
