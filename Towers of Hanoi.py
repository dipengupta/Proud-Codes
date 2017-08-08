'''

This is the solution for 'Towers of Hanoi'
Only one ring is to be moved as displayed on the screen.

'''



def print_move(fr, to) :
    print ('move from ' + str(fr) + ' to ' + str(to))

def Towers(n, fr, to, spare) :
    '''
    n (int) : number of rings
    fr (str) : stack from which to pick rings
    to (str) : final stack in which the rings are to be kept
    spare (str) : spare stack
    '''

    if n==1 :
        print_move(fr,to)
    else :
        Towers (n-1, fr, spare, to)
        Towers (1, fr, to, spare)
        Towers (n-1, spare, to, fr)

print(Towers(4,'1','2','3'))
