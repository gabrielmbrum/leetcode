
para checar se é um problema deste tipo ou não, tem os seguintes passos

```tips
To, find out a sliding window problem :
	-> First thing is, we have given something like an "Array" | OR | "String" 
	-> Second thing is, they are talking about either "subsequence" | OR | "substring" 
	-> And third most thing is, either we have given a "window size i.e. k" | OR | we have to "manually find out window size"
```

a example of problem like that is the `Longest Substring WIthout Repeating Characters`

there is two types of sliding window problems:
1. FIX SIZE 
2. VARIABLE SIZE

youtube video: https://youtu.be/dOonV4byDEg?si=zSketOc5GFdsvTrr


### fix size

um exemplo é o problema de a maior soma de cinco números dentro de um array

por exemplo, com K = 5

podemos iniciar no vetor com os cinco primeiros números, na próxima iteração, ao inves de somar de i = 1 até i = 5, subtrai-se a[0] e adiciona-se a[5], e assim por diante

```pseudo
cur = best = sum(a[:k])
for r in range(k, len(a)):
	cur = cur + a[r] - a[r - k]
	best = max(best, cur)
```

### variable size

exemplo é achar o maior subarray com a soma < *S* 

temos dois ponteiros
i = -1
j = 0

então, vamos continuamente movendo o *j* para direita, até que passe o limite da soma, quando isso ocorrer, movemos o *i* para direita, até que a soma seja menor que o limite

continua esse processo até o fim do array

```pseudo
l, cur, best = -1, 0, 0
for r in range(len(a)):
	cur += a[r]
	while cur >= s:
		l += 1
		cur -= a[l]
	best = max(best, r - 1)
```



