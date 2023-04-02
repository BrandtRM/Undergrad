#lang racket
#| Problem 1 |#

(define (pyth a b c)
  (cond [(= a 0) (sqrt (- (* c c) (* b b)))]
        [(= b 0) (sqrt (- (* c c) (* a a)))]
        [(= c 0) (sqrt (+ (* a a) (* b b)))]))



#| Problem 2 |#

(define (iradius A B C)
  (let ([S (/ (+ A B C) 2)])
    (/ (sqrt (* (- S A) (- S B) (- S C))) S)))



#| Problem 3 |#

(define (a n)
  (if (= n 0)
      1
      (* n (a (- n 1)))))



#| Problem 4 |#

(define (divides a b) (= (modulo b a) 0))
(define (smooth n k)
        (and (>= k 2)
             (or (divides k n)
             (smooth n (- k 1)))))
(define (isprime? p)
        (not (smooth p (floor (sqrt p )))))

(define (prime-reciprocals n)
  (if (= n 2)
      (/ 1 2)
  (if (isprime? n)
      (+ (/ 1 n) (prime-reciprocals (- n 1)))
      (prime-reciprocals (- n 1)))))



#| Problem 5 |#

(define (perfect-square? n)
  (if (integer? (sqrt n))
      #t
      #f))