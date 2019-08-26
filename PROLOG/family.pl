%
%                  emma_watson
%                /                   
%          johny             
%       /       \
%   john         stone
%       \      /
%          emma
%              \
%                john_f_k
%

male(john).
male(johny).
male(john_f_k).

female(emma).
female(stone).
female(emma_watson).

parent(john,johny).
parent(john,emma).
parent(johny,emma_watson).
parent(emma,stone).
parent(emma,john_f_k).
parent(johny,stone).

parent(X,stone),male(X).
X.