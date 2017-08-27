'''

This is a small program to get an idea of scaled GRE score.
User inputs max marks, verbal raw score, and quants raw score.

The scores obtained are the average values from dictionaries provided.

The keys in these dictionares is the raw score obtained.
The first score in the list is of Verbal Reasoning, 
and the second score is of Quantitative Reasoning.

This is ny no means an ideal score generator, but it does 
give you a pretty decent idea, and honestly, it's kinda tough on you.

IMP : This only shows scores of the upper range.
So, if your score is below, say, 290, you're out of luck. It'll crash.

Coded by Dipen on 7th August 2017.

'''


#ETS GRE Practise Test 1 (offline, out of 50)
score_conversion_table_1 = {
					
					50 : [170,170],
					49 : [170,170],
					48 : [170,170],
					47 : [170,170],
					46 : [169,169],
					45 : [168,168],
					44 : [167,167],
					43 : [166,165],
					42 : [165,164],
					41 : [164,163],
					40 : [163,162],
					39 : [162,161],
					38 : [162,160],
					37 : [161,159],
					36 : [160,159],
					35 : [159,158],
					34 : [159,157],
					33 : [158,156],
					32 : [157,155],
					31 : [156,155],
					30 : [156,154],
					29 : [155,153],
					28 : [154,153],
					27 : [154,152],
					26 : [153,151],
					25 : [152,150],
					24 : [152,150],
					23 : [151,149],
					22 : [150,148],
					21 : [149,148],
					20 : [149,147]
}



#ETS GRE Practise Test 2 (offline, out of 50)
score_conversion_table_2 = {
					
					50 : [170,170],
					49 : [170,169],
					48 : [169,167],
					47 : [168,165],
					46 : [167,164],
					45 : [166,163],
					44 : [165,162],
					43 : [164,161],
					42 : [163,160],
					41 : [162,159],
					40 : [161,158],
					39 : [160,157],
					38 : [160,157],
					37 : [159,156],
					36 : [158,155],
					35 : [158,155],
					34 : [157,154],
					33 : [156,153],
					32 : [156,153],
					31 : [155,152],
					30 : [154,152],
					29 : [154,151],
					28 : [153,150],
					27 : [152,150],
					26 : [152,149],
					25 : [151,149],
					24 : [150,148],
					23 : [149,148],
					22 : [149,147],
					21 : [148,146],
					20 : [147,146]
}


#found this online (out of 40)
score_conversion_table_3 = {

					40 : [170,170],
					39 : [169,169],
					38 : [168,168],
					37 : [167,167],
					36 : [166,166],
					35 : [165,165],
					34 : [164,164],
					33 : [163,163],
					32 : [162,162],
					31 : [161,161],
					30 : [160,160],
					29 : [159,159],
					28 : [158,158],
					27 : [157,157],
					26 : [156,156],
					25 : [155,155],
					24 : [154,154],
					23 : [153,153],
					22 : [152,152],
					21 : [151,151],
					20 : [150,150],
					19 : [149,149],
					18 : [148,148],
					17 : [147,147],
					16 : [146,146],
					15 : [145,145],
					14 : [144,144],
					13 : [143,143],
					12 : [142,142]
	
}


#my interpretation
score_conversion_table_4 = {
					
					50 : [170,170],
					49 : [170,170],
					48 : [169,169],
					47 : [168,168],
					46 : [168,167],
					45 : [167,167],
					44 : [166,166],
					43 : [165,165],
					42 : [164,164],
					41 : [163,163],
					40 : [163,162],
					39 : [162,161],
					38 : [162,160],
					37 : [161,159],
					36 : [161,159],
					35 : [160,158],
					34 : [159,157],
					33 : [159,156],
					32 : [158,155],
					31 : [157,155],
					30 : [156,154],
					29 : [155,153],
					28 : [155,153],
					27 : [154,152],
					26 : [153,151],
					25 : [152,150],
					24 : [152,150],
					23 : [151,149],
					22 : [150,148],
					21 : [149,148],
					20 : [149,147]
}




def calc_scaled_verbal_score(verbal_raw_score) :
	'''

	input : verbal raw score
	output : scaled verbal score

	This calculates the percentage scored, 
	and then gets an equivalent for 50 marks.
	The average from all dictionaries is returned.

	'''
	ratio = verbal_raw_score/max_marks
	key1 = ratio*50
	key2 = ratio*40

	x1 = score_conversion_table_1[int(key1)][0]
	x2 = score_conversion_table_2[int(key1)][0]
	x3 = score_conversion_table_3[int(key2)][0]
	x4 = score_conversion_table_4[int(key1)][0]

	return (int((x1+x2+x3+x4)/4))





def calc_scaled_quants_score(quants_raw_score) : 
	'''

	input : quants raw score
	output : scaled verbal score

	This calculates the percentage scored, 
	and then gets an equivalent for 50 marks.
	The average from all dictionaries is returned.

	'''

	ratio = quants_raw_score/max_marks
	key1 = ratio*50
	key2 = ratio*40

	x1 = score_conversion_table_1[int(key1)][1]
	x2 = score_conversion_table_2[int(key1)][1]
	x3 = score_conversion_table_3[int(key2)][1]
	x4 = score_conversion_table_4[int(key1)][1]

	return (int((x1+x2+x3+x4)/4))



max_marks = int(input("Enter max raw score (40 or 50) : "))
verbal_raw_score = input("Enter Verbal Raw Score : ")
quants_raw_score = input("Enter Quants Raw Score : ")


verbal_scaled_score = calc_scaled_verbal_score(int(verbal_raw_score))
quants_scaled_score = calc_scaled_quants_score(int(quants_raw_score))


print("Scaled Verbal Score : " + str(verbal_scaled_score))
print("Scaled Quants Score : " + str(quants_scaled_score))
print("Total Score : " + str(verbal_scaled_score + quants_scaled_score))




