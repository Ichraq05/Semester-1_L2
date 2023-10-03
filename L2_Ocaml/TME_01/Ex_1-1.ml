let rec sum_chiffres(n : int) : int =
    if n<11 then 
    n
    else 
    n-1-((n/10)*10) + sum_chiffres(n/10)