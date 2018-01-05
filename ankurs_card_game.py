'''

This is a simulation of a card game whose rules are as follows : (no input is required btw)

There's a standard deck of cards, which is shuffled fairly and distributed amongst 4 people.
They are only allowed to see the top card of their pile. And all play is in regards to that card.
	
The motive of the game is to arrange the cards in order, starting from Seven of Hearts, up and down
without skipping any card. Another shape may only be started if the person posesses a seven of that shape.
All other numbers must follow in sequence. The person who gets done with all their cards (i.e has none left)
is the winner. The other places are calculated upon how many cards are left with the other players. Each card
has points equal to it's numeric value, and the person with the highest points loses.


Alrighty, logic/style of coding :

 	Here I have made use of several helper functions, and tbh, it was quite fun.
	This is probably the first proper (big-sized) python simulation I've done, complete with docstrings and everything.
 	I know the logic can be improved tremendously, but atm it's 4 in the morning, and I'm super glad it works.
 	I made/implemented (almost) all of the datastructures myself, and it was quite fun doing that tbh.

Inspiration :
	
	This was an actual game me and a group of friends played while on vacation, and honestly, all I could think
	about while playing that was how nicely it could be automated, so, here we are.

Coded by Dipen. 6th Jan, 2018.

'''


from random import *
import pprint


'''

Queue Info : 
Structure : rear => => => => => front

'''
class Queue():

	def __init__(self):
		self.items = []

	def isEmpty(self):
		return self.items == []

	def enqueue(self, item):
		self.items.insert(0,item)

	def dequeue(self):
		return self.items.pop()

	def size(self):
		return len(self.items)

	def get_queue(self):
		return self.items   

	def get_front_element(self):
		return self.items[self.size()-1]

	def move_top_card_to_bottom(self):
		temp = self.get_front_element()
		self.dequeue()
		self.enqueue(temp)


class Cards():
	
	def __init__(self) :
		self.deck = {
			"ace" : 0,
			"two" : 0,
			"three" : 0,
			"four" : 0,
			"five" : 0,
			"six" : 0,
			"seven" : 0,
			"eight" : 0,
			"nine" : 0,
			"ten"  : 0,
			"jack" : 0,
			"queen" : 0,
			"king" : 0
		}


	def alter_deck(self,name) :
		if self.deck[name] == 0 :
			self.deck[name] = 1

	def get_deck(self) :
		proper_deck = [
			("king" , self.deck["king"]),
			("queen" , self.deck["queen"]),
			("jack" , self.deck["jack"]),
			("ten"  , self.deck["ten"]),
			("nine" , self.deck["nine"]),
			("eight" , self.deck["eight"]),
			("seven" , self.deck["seven"]),
			("six" , self.deck["six"]),
			("five" , self.deck["five"]),
			("four" , self.deck["four"]),
			("three" , self.deck["three"]),
			("two" , self.deck["two"]),
			("ace" , self.deck["ace"])
		]
		return (proper_deck)

	def terminating_condition(self):
		flag = True
		for key, value in self.deck.items():
			if value == 0 :
				flag = False
				break
		
		return flag


def get_current_global_status() :
	'''

	returns [text on screen] : gives the current overview of all the cards
	(makes ues of Class Cards)
	
	'''

	print("diamonds : ")
	pprint.pprint(diamonds.get_deck())

	print("hearts : ")
	pprint.pprint(hearts.get_deck())

	print("clubs : ")
	pprint.pprint(clubs.get_deck())
	
	print("spades : ")
	pprint.pprint(spades.get_deck())


def get_current_player_status_all() :
	'''

	returns [text on screen]: gives the current overview of all the players' cards (in order)
	(makes ues of Class Queue)
	
	'''
	print("These are the queues of all players at the moment : ")

	print("player_1 : " + str(player_1.size()) + " card(s)")
	pprint.pprint(player_1.get_queue())

	print("player_2 : " + str(player_2.size()) + " card(s)")
	pprint.pprint(player_2.get_queue())

	print("player_3 : " + str(player_3.size()) + " card(s)")
	pprint.pprint(player_3.get_queue())

	print("player_4 : " + str(player_4.size()) + " card(s)")
	pprint.pprint(player_4.get_queue())


def shuffle_deck() :
	'''

	output [insertion of values in queues] : This shuffles up strings and assigns them to queues of players 1,2,3,4.
	
	'''

	kind = 'diamonds hearts clubs spades'.split()
	num = 'ace two three four five six seven eight nine ten jack queen king'.split()
	
	shuffle(kind)
	shuffle(num)
	
	shuffled_deck = []

	for ele1 in num :
		for ele2 in kind : 
			shuffled_deck.append(ele1  + " of " + ele2)

	shuffle(shuffled_deck)

	ctr = 0

	while(player_1.size()!=13 and player_2.size()!=13 and player_3.size()!=13 and player_4.size()!=13) :
		player_1.enqueue(shuffled_deck[ctr])
		ctr = ctr + 1
		player_2.enqueue(shuffled_deck[ctr])
		ctr = ctr + 1
		player_3.enqueue(shuffled_deck[ctr])
		ctr = ctr + 1
		player_4.enqueue(shuffled_deck[ctr])
		ctr = ctr + 1


def str_to_num(x) :
	'''

	~~helper functon~~
	input [string] : the whole term of the card
	output [int] : returns appropriate number	 
	
	'''
	split_terms = x.split()
	split_num = split_terms[0]

	if split_num == 'ace' :
		return 1
	if split_num == 'two' :
		return 2
	if split_num == 'three' :
		return 3
	if split_num == 'four' :
		return 4
	if split_num == 'five' :
		return 5
	if split_num == 'six' :
		return 6
	if split_num == 'seven' :
		return 7
	if split_num == 'eight' :
		return 8
	if split_num == 'nine' :
		return 9
	if split_num == 'ten' :
		return 10
	if split_num == 'jack' :
		return 11
	if split_num == 'queen' :
		return 12
	if split_num == 'king' :
		return 13


def str_to_shape(x) :
	'''

	~~helper functon~~
	input [string] : the whole term of the card
	output [string] : returns appropriate shape	 
	
	'''
	split_terms = x.split()
	return(split_terms[2])


def play_game() :
	'''

	Damn, this will be long...

	
	Alrighty, 

	 	Here I have made use of several helper functions, and tbh, it was quite fun.
	 	I know the logic can be improved tremendously, but atm it's 4 in the morning, and I'm super glad it works.
	


	pointer/flags to keep track of cards placed in deck :
	
	[1,2,3,4,5,6,7,8,9,10,J,Q,K]
	[rear <===============> front]

	here, upon getting 7 (in any shape), front will be equal to 8, and rear will be equal to 6

	
	'''

	def mark_chart(x) :
		'''

		~~helper functon~~
		input [string] : the whole term of the card
		output : updates value in global deck (Class Card) to 1	 
		
		'''
		split_terms = x.split()
		split_num = split_terms[0]
		split_shape = split_terms[2]

		if split_shape == 'diamonds' :
			diamonds.alter_deck(split_num)

		if split_shape == 'hearts' :
			hearts.alter_deck(split_num)

		if split_shape == 'clubs' :
			clubs.alter_deck(split_num)

		if split_shape == 'spades' :
			spades.alter_deck(split_num)



	def starting_move():
		'''

		~~helper functon~~
		This is the starting move where the player who has "seven of hearts" is found.

		output [text on screen]: player's name is printed, and value is marked in the chart. 
		returns [integer] : total number of turns, so that next player can be accounted for. 
		
		'''
		
		total_turns = 0
		
		while True :
			
			if player_1.get_front_element() == 'seven of hearts' :
				print("Player 1 Started")
				mark_chart(player_1.get_front_element())
				player_1.dequeue()
				total_turns = total_turns + 1
				break 
			
			else :
				player_1.move_top_card_to_bottom()
				total_turns = total_turns + 1
				if player_2.get_front_element() == 'seven of hearts' :
					print("Player 2 Started")
					mark_chart(player_2.get_front_element())
					player_2.dequeue()
					total_turns = total_turns + 1
					break 

				else :
					player_2.move_top_card_to_bottom()
					total_turns = total_turns + 1
					if player_3.get_front_element() == 'seven of hearts' :
						print("Player 3 Started")
						mark_chart(player_3.get_front_element())
						player_3.dequeue()
						total_turns = total_turns + 1
						break 

					else :
						player_3.move_top_card_to_bottom()
						total_turns = total_turns + 1
						if player_4.get_front_element() == 'seven of hearts' :
							print("Player 4 Started")
							mark_chart(player_4.get_front_element())
							player_4.dequeue()
							total_turns = total_turns + 1
							break 
						else :
							player_4.move_top_card_to_bottom()
							total_turns = total_turns + 1

		print("It took " + str(total_turns) + " turns to find seven of hearts")
		return total_turns



	# ========= Main Game Logic ========= #


	# here, chance also counts for total number of turns.
	chance = starting_move()
	chance = chance + 1

	
	
	hearts_front = 8
	hearts_rear = 6
	#starts with heart

	shapes_unlocked = ['hearts']
	seven_list = ['seven of diamonds', 'seven of clubs', 'seven of spades']

	while not (diamonds.terminating_condition() and hearts.terminating_condition() and clubs.terminating_condition() and spades.terminating_condition()) :
	
		#player 1's chance : 
		if chance%4 == 1 :

			print("Chance " + str(chance) + " : player_1 will play now")
			
			current_card = player_1.get_front_element()

			if current_card in seven_list :
				mark_chart(current_card)
				seven_list.remove(current_card)

				if current_card == 'seven of diamonds' :
					shapes_unlocked.append('diamonds')
					diamonds_front = 8
					diamonds_rear = 6

				if current_card == 'seven of clubs' : 
					shapes_unlocked.append('clubs')
					clubs_front = 8
					clubs_rear = 6

				if current_card == 'seven of spades' : 
					shapes_unlocked.append('spades')
					spades_front = 8
					spades_rear = 6

				player_1.dequeue()

			else :

				current_card_shape = str_to_shape(current_card)
				current_card_num = str_to_num(current_card)

				print(current_card_shape,current_card_num)

				if current_card_shape in shapes_unlocked :
					


					if current_card_shape == 'diamonds' :

						if current_card_num == diamonds_front :
							mark_chart(player_1.get_front_element())
							diamonds_front = diamonds_front + 1 
							player_1.dequeue()
							if player_1.size()==0 :
								return("Player 1 Won.")

						elif current_card_num == diamonds_rear :
							mark_chart(player_1.get_front_element())
							diamonds_rear = diamonds_rear - 1 
							player_1.dequeue()
							if player_1.size()==0 :
								return("Player 1 Won.")

						else :
							player_1.move_top_card_to_bottom()



					if current_card_shape == 'hearts' :

						if current_card_num == hearts_front :
							mark_chart(player_1.get_front_element())
							hearts_front = hearts_front + 1 
							player_1.dequeue()
							if player_1.size()==0 :
								return("Player 1 Won.")

						elif current_card_num == hearts_rear :
							mark_chart(player_1.get_front_element())
							hearts_rear = hearts_rear - 1 
							player_1.dequeue()
							if player_1.size()==0 :
								return("Player 1 Won.")

						else :
							player_1.move_top_card_to_bottom()

					if current_card_shape == 'clubs' :

						if current_card_num == clubs_front :
							mark_chart(player_1.get_front_element())
							clubs_front = clubs_front + 1 
							player_1.dequeue()
							if player_1.size()==0 :
								return("Player 1 Won.")

						elif current_card_num == clubs_rear :
							mark_chart(player_1.get_front_element())
							clubs_rear = clubs_rear - 1 
							player_1.dequeue()
							if player_1.size()==0 :
								return("Player 1 Won.")

						else :
							player_1.move_top_card_to_bottom()


					if current_card_shape == 'spades' :

						if current_card_num == spades_front :
							mark_chart(player_1.get_front_element())
							spades_front = spades_front + 1 
							player_1.dequeue()
							if player_1.size()==0 :
								return("Player 1 Won.")

						elif current_card_num == spades_rear :
							mark_chart(player_1.get_front_element()) # 
							spades_rear = spades_rear - 1 
							player_1.dequeue()
							if player_1.size()==0 :
								return("Player 1 Won.")

						else :
							player_1.move_top_card_to_bottom()

				else :
					player_1.move_top_card_to_bottom()


			chance = chance + 1



		#player 2's chance : 
		if chance%4 == 2 :

			print("Chance " + str(chance) + " : player_2 will play now")
			
			current_card = player_2.get_front_element()

			if current_card in seven_list :
				mark_chart(current_card)
				seven_list.remove(current_card)

				if current_card == 'seven of diamonds' :
					shapes_unlocked.append('diamonds')
					diamonds_front = 8
					diamonds_rear = 6

				if current_card == 'seven of clubs' : 
					shapes_unlocked.append('clubs')
					clubs_front = 8
					clubs_rear = 6

				if current_card == 'seven of spades' : 
					shapes_unlocked.append('spades')
					spades_front = 8
					spades_rear = 6

				player_2.dequeue()

			else :

				current_card_shape = str_to_shape(current_card)
				current_card_num = str_to_num(current_card)

				print(current_card_shape,current_card_num)

				if current_card_shape in shapes_unlocked :
					


					if current_card_shape == 'diamonds' :

						if current_card_num == diamonds_front :
							mark_chart(player_2.get_front_element())
							diamonds_front = diamonds_front + 1 
							player_2.dequeue()
							if player_2.size()==0 :
								return("Player 2 Won.")

						elif current_card_num == diamonds_rear :
							mark_chart(player_2.get_front_element())
							diamonds_rear = diamonds_rear - 1 
							player_2.dequeue()
							if player_2.size()==0 :
								return("Player 2 Won.")

						else :
							player_2.move_top_card_to_bottom()



					if current_card_shape == 'hearts' :

						if current_card_num == hearts_front :
							mark_chart(player_2.get_front_element())
							hearts_front = hearts_front + 1 
							player_2.dequeue()
							if player_2.size()==0 :
								return("Player 2 Won.")

						elif current_card_num == hearts_rear :
							mark_chart(player_2.get_front_element())
							hearts_rear = hearts_rear - 1 
							player_2.dequeue()
							if player_2.size()==0 :
								return("Player 2 Won.")

						else :
							player_2.move_top_card_to_bottom()

					if current_card_shape == 'clubs' :

						if current_card_num == clubs_front :
							mark_chart(player_2.get_front_element())
							clubs_front = clubs_front + 1 
							player_2.dequeue()
							if player_2.size()==0 :
								return("Player 2 Won.")

						elif current_card_num == clubs_rear :
							mark_chart(player_2.get_front_element())
							clubs_rear = clubs_rear - 1 
							player_2.dequeue()
							if player_2.size()==0 :
								return("Player 2 Won.")

						else :
							player_2.move_top_card_to_bottom()


					if current_card_shape == 'spades' :

						if current_card_num == spades_front :
							mark_chart(player_2.get_front_element())
							spades_front = spades_front + 1 
							player_2.dequeue()
							if player_2.size()==0 :
								return("Player 2 Won.")

						elif current_card_num == spades_rear :
							mark_chart(player_2.get_front_element()) # 
							spades_rear = spades_rear - 1 
							player_2.dequeue()
							if player_2.size()==0 :
								return("Player 2 Won.")
								
						else :
							player_2.move_top_card_to_bottom()

				else :
					player_2.move_top_card_to_bottom()


			chance = chance + 1



		#player 3's chance : 
		if chance%4 == 3 :

			print("Chance " + str(chance) + " : player_3 will play now")
			
			current_card = player_3.get_front_element()

			if current_card in seven_list :
				mark_chart(current_card)
				seven_list.remove(current_card)

				if current_card == 'seven of diamonds' :
					shapes_unlocked.append('diamonds')
					diamonds_front = 8
					diamonds_rear = 6

				if current_card == 'seven of clubs' : 
					shapes_unlocked.append('clubs')
					clubs_front = 8
					clubs_rear = 6

				if current_card == 'seven of spades' : 
					shapes_unlocked.append('spades')
					spades_front = 8
					spades_rear = 6

				player_3.dequeue()

			else :

				current_card_shape = str_to_shape(current_card)
				current_card_num = str_to_num(current_card)

				print(current_card_shape,current_card_num)

				if current_card_shape in shapes_unlocked :
					


					if current_card_shape == 'diamonds' :

						if current_card_num == diamonds_front :
							mark_chart(player_3.get_front_element())
							diamonds_front = diamonds_front + 1 
							player_3.dequeue()
							if player_3.size()==0 :
								return("Player 3 Won.")

						elif current_card_num == diamonds_rear :
							mark_chart(player_3.get_front_element())
							diamonds_rear = diamonds_rear - 1 
							player_3.dequeue()
							if player_3.size()==0 :
								return("Player 3 Won.")

						else :
							player_3.move_top_card_to_bottom()



					if current_card_shape == 'hearts' :

						if current_card_num == hearts_front :
							mark_chart(player_3.get_front_element())
							hearts_front = hearts_front + 1 
							player_3.dequeue()
							if player_3.size()==0 :
								return("Player 3 Won.")

						elif current_card_num == hearts_rear :
							mark_chart(player_3.get_front_element())
							hearts_rear = hearts_rear - 1 
							player_3.dequeue()
							if player_3.size()==0 :
								return("Player 3 Won.")

						else :
							player_3.move_top_card_to_bottom()

					if current_card_shape == 'clubs' :

						if current_card_num == clubs_front :
							mark_chart(player_3.get_front_element())
							clubs_front = clubs_front + 1 
							player_3.dequeue()
							if player_3.size()==0 :
								return("Player 3 Won.")

						elif current_card_num == clubs_rear :
							mark_chart(player_3.get_front_element())
							clubs_rear = clubs_rear - 1 
							player_3.dequeue()
							if player_3.size()==0 :
								return("Player 3 Won.")

						else :
							player_3.move_top_card_to_bottom()


					if current_card_shape == 'spades' :

						if current_card_num == spades_front :
							mark_chart(player_3.get_front_element())
							spades_front = spades_front + 1 
							player_3.dequeue()
							if player_3.size()==0 :
								return("Player 3 Won.")

						elif current_card_num == spades_rear :
							mark_chart(player_3.get_front_element()) # 
							spades_rear = spades_rear - 1 
							player_3.dequeue()
							if player_3.size()==0 :
								return("Player 3 Won.")
								
						else :
							player_3.move_top_card_to_bottom()

				else :
					player_3.move_top_card_to_bottom()


			chance = chance + 1



		#player 4's chance : 
		if chance%4 == 0 :

			print("Chance " + str(chance) + " : player_4 will play now")
			
			current_card = player_4.get_front_element()

			if current_card in seven_list :
				mark_chart(current_card)
				seven_list.remove(current_card)

				if current_card == 'seven of diamonds' :
					shapes_unlocked.append('diamonds')
					diamonds_front = 8
					diamonds_rear = 6

				if current_card == 'seven of clubs' : 
					shapes_unlocked.append('clubs')
					clubs_front = 8
					clubs_rear = 6

				if current_card == 'seven of spades' : 
					shapes_unlocked.append('spades')
					spades_front = 8
					spades_rear = 6

				player_4.dequeue()

			else :

				current_card_shape = str_to_shape(current_card)
				current_card_num = str_to_num(current_card)

				print(current_card_shape,current_card_num)

				if current_card_shape in shapes_unlocked :
					


					if current_card_shape == 'diamonds' :

						if current_card_num == diamonds_front :
							mark_chart(player_4.get_front_element())
							diamonds_front = diamonds_front + 1 
							player_4.dequeue()
							if player_4.size()==0 :
								return("Player 4 Won.")

						elif current_card_num == diamonds_rear :
							mark_chart(player_4.get_front_element())
							diamonds_rear = diamonds_rear - 1 
							player_4.dequeue()
							if player_4.size()==0 :
								return("Player 4 Won.")

						else :
							player_4.move_top_card_to_bottom()



					if current_card_shape == 'hearts' :

						if current_card_num == hearts_front :
							mark_chart(player_4.get_front_element())
							hearts_front = hearts_front + 1 
							player_4.dequeue()
							if player_4.size()==0 :
								return("Player 4 Won.")

						elif current_card_num == hearts_rear :
							mark_chart(player_4.get_front_element())
							hearts_rear = hearts_rear - 1 
							player_4.dequeue()
							if player_4.size()==0 :
								return("Player 4 Won.")

						else :
							player_4.move_top_card_to_bottom()

					if current_card_shape == 'clubs' :

						if current_card_num == clubs_front :
							mark_chart(player_4.get_front_element())
							clubs_front = clubs_front + 1 
							player_4.dequeue()
							if player_4.size()==0 :
								return("Player 4 Won.")

						elif current_card_num == clubs_rear :
							mark_chart(player_4.get_front_element())
							clubs_rear = clubs_rear - 1 
							player_4.dequeue()
							if player_4.size()==0 :
								return("Player 4 Won.")

						else :
							player_4.move_top_card_to_bottom()


					if current_card_shape == 'spades' :

						if current_card_num == spades_front :
							mark_chart(player_4.get_front_element())
							spades_front = spades_front + 1 
							player_4.dequeue()
							if player_4.size()==0 :
								return("Player 4 Won.")

						elif current_card_num == spades_rear :
							mark_chart(player_4.get_front_element()) # 
							spades_rear = spades_rear - 1 
							player_4.dequeue()
							if player_4.size()==0 :
								return("Player 4 Won.")
								
						else :
							player_4.move_top_card_to_bottom()

				else :
					player_4.move_top_card_to_bottom()


			chance = chance + 1


def make_scoreboard() :
	'''

	output [text on screen] : displays results on screen 

	'''
	
	get_current_global_status()
	get_current_player_status_all()


	player_1_end_score = 0
	player_2_end_score = 0
	player_3_end_score = 0
	player_4_end_score = 0


	for ele in player_1.get_queue() :
		player_1_end_score = player_1_end_score + str_to_num(ele)

	for ele in player_2.get_queue() :
		player_2_end_score = player_2_end_score + str_to_num(ele)

	for ele in player_3.get_queue() :
		player_3_end_score = player_3_end_score + str_to_num(ele)

	for ele in player_4.get_queue() :
		player_4_end_score = player_4_end_score + str_to_num(ele)

	all_scores = {
			"Player 1" : player_1_end_score,
			"Player 2" : player_2_end_score,
			"Player 3" : player_3_end_score,
			"Player 4" : player_4_end_score
		}

	print("SCOREBOARD : ")
	
	print("Winner : " + str(min(all_scores, key=all_scores.get)))
	del all_scores[min(all_scores, key=all_scores.get)]

	for x in range(3) :
		k = str(min(all_scores, key=all_scores.get))
		print("Place " + str((x+2)) + " : " + k + " (" + str(all_scores[k])+" Points)")
		del all_scores[k]



# ======= Main Function ======== #



diamonds = Cards()
hearts = Cards()
clubs = Cards()
spades = Cards()

player_1 = Queue()
player_2 = Queue()
player_3 = Queue()
player_4 = Queue()

shuffle_deck()

print(play_game())

make_scoreboard()


