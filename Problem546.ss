;(define floorRevenge
;	(lambda (n k)
;		(let ([answers (listRange 1 k)]
;			  [i k]
;			  [addBy 1])
;			(do ([addBy 1 (+ addBy (nthElement answers (floor (/ i (* k k)))))]
;				 [answers answers 
;				 	(if (>= (- n i) k)
;				 		(updateAnswers answers addBy (- i 1) (+ i k -2))
;				 		(updateAnswers answers addBy (- i 1) (+ n 1)))]
;				 [i i (+ i k)])
;				((begin (display answers) (> i n))
;				 (car (reverse answers)))))))

;(define floorRevenge2
;	(lambda (n k)
;		(for (((define answers (listRange 1 k)) (define i k) (define addBy 1)) :
;			(> i n) :
;			(set! addBy (+ addBy (nthElement answers (floor (/ i (* k k))))))
;			(if (>= (- n i) k)
;				(set! answers (updateAnswers answers addBy (- i 1) (+ i k -2)))
;				(set! answers (updateAnswers answers addBy (- i 1) (+ n 1))))
;			(set! i (+ i k)))
;			(display answers)
;			(newline))))


(define updateAnswers
	(lambda (ls addBy start end)
		(if (= start end)
			(append ls (list (+ (nthElement ls start) addBy)))
			(updateAnswers
				(append ls (list (+ (nthElement ls start) addBy)))
				addBy 
				(+ 1 start) 
				end))))

(define nthElement
	(lambda (ls n)
		(if (= n 0)
			(car ls)
			(nthElement (cdr ls) (- n 1)))))

(define listRange
	(lambda (x y)
		(if (= x y)
			(list x)
			(cons x (listRange (+ 1 x) y)))))

(define-syntax for
	(syntax-rules (:)
		[(_ ((init ...) : test : update ...) body ...)
		 (begin
		 	init ...
		 	(let loop ()
		 		(if test
		 			(begin
		 				body ...
		 				update ...
		 				(loop)))))]))