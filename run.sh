# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 17:57:54 by wwallas-          #+#    #+#              #
#    Updated: 2022/09/04 07:22:15 by wwallas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# script feito pelo luiz
#https://github.com/librity/ft_push_swap/blob/master/scripts/run.sh

PUSH_SWAP_DIR="."
CHECKER="./checker_linux"

PUSH_SWAP=$PUSH_SWAP_DIR/push_swap

# Value of INT_MAX is +2147483647.
# Value of INT_MIN is -2147483648.

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK="\033[0;30m"
R="\033[0;31m"
G="\033[0;32m"
Y="\033[0;33m"
B="\033[0;34m"
P="\033[0;35m"
C="\033[0;36m"
W="\033[0;37m"
# Bold
BKB="\033[1;30m"
RB="\033[1;31m"
GB="\033[1;32m"
YB="\033[1;33m"
BB="\033[1;34m"
PB="\033[1;35m"
CB="\033[1;36m"
WB="\033[1;37m"
# Reset Color
RC="\033[0m"

divider() {
	echo -e "${P}=======================================================${RC}"
}

separator() {
	divider
	echo
}

bad_stacks_banner() {
	divider
	echo -e "${RB}BAD STACKS: (SHOULD PRINT \"Error\\\\n\" AND RETURN 1) ${RC}"
	separator
}

empty_stacks_banner() {
	divider
	echo -e "${GB}EMPTY STACK: (SHOULDN'T PRINT ANYTHING AND RETURN 0) ${RC}"
	separator
}

good_stacks_banner() {
	divider
	echo -e "${GB}GOOD STACKS: (CHECKER SHOULD RETURN \"OK\\\\n\") ${RC}"
	separator
}

hundred_stack_banner() {
	echo -e """${YB}
	HUNDRED-STACK BENCHMARK
	==========================
	| OPERATIONS     | GRADE |
	==========================
	| less than 700  |   5   |
	| less than 900  |   4   |
	| less than 1100 |   3   |
	| less than 1300 |   2   |
	| less than 1500 |   1   |
	==========================
${RC}"""
	separator
}

fivehundred_stack_banner() {
	echo -e """${YB}
	FIVEHUNDRED-STACK BENCHMARK
	===========================
	| OPERATIONS      | GRADE |
	===========================
	| less than 5500  |   5   |
	| less than 7000  |   4   |
	| less than 8500  |   3   |
	| less than 10000 |   2   |
	| less than 11500 |   1   |
	===========================
${RC}"""
	separator
}

run_ps() {
	STACK="$1"

	echo -e "${C}EXECUTING:\n\
${CB}${PUSH_SWAP} $STACK${RC}"
	${PUSH_SWAP} $STACK

	echo -e "${Y}RETURN: ${YB}$?${RC}"
	separator
}

run_checker() {
	if [ "${2}" == "" ]; then
		CHECKER_RESULT=$(echo -n "${2}" | $CHECKER $1)
	else
		CHECKER_RESULT=$(echo "${2}" | $CHECKER $1)
	fi

	echo -en "${Y}CHECKER: "
	if [ "$CHECKER_RESULT" == "OK" ]; then
		echo -en "${GB}OK${RC}"
	else
		echo -en "${RB}KO${RC}"
	fi
	echo -e "${RC}"
}

count_moves() {
	echo -en "${B}MOVES: ${BB}"
	if [ "${1}" == "" ]; then
		echo 0
	else
		echo -n "${1}" | wc -l
	fi
	echo -e "${RC}"
}

run_ps_with_checker() {
	echo -e "${C}EXECUTING:\n\
${CB}${PUSH_SWAP} $1${RC}"
	PS_RESULT=$(${PUSH_SWAP} $1)

	run_checker "$1" "${PS_RESULT}"
	count_moves "${PS_RESULT}"
	separator
}

################################################################################
# INITIALIZE
################################################################################

make -C $PUSH_SWAP_DIR re || exit

################################################################################
# BAD STACKS
################################################################################

run_bad_stacks() {
	bad_stacks_banner

	run_ps "2 one 3"
	run_ps "2 1.1 3"
	run_ps "2 1 -3.2"
	run_ps "2 +2147483648 3"
	run_ps "2 2147483648 3"
	run_ps "2 -2147483649 3"
	run_ps "2 2 3"
	run_ps "1 2 2 3"
	run_ps "3 2 1 3"
	run_ps "999999999999999999999999999999999999999999999999999999999999"
	run_ps "1 2 3 456	42	13	4684 -99999999999999999999999999999999999999999999999999999999999"
	run_ps "-50	- "
}
run_bad_stacks

################################################################################
# EMPTY STACK
################################################################################

run_empty_stack() {
	empty_stacks_banner
	run_ps ""
}
run_empty_stack

################################################################################
# GOOD STACKS
################################################################################

run_good_stacks() {
	good_stacks_banner

	run_ps_with_checker "1"

	run_ps_with_checker "1 2"
	run_ps_with_checker "2 1"

	run_ps_with_checker "2 +2147483647 3"
	run_ps_with_checker "2 2147483647 3"
	run_ps_with_checker "2 -2147483648 3"
	run_ps_with_checker "-2147483648 -2147483647 2147483647"
	run_ps_with_checker "-2147483648 2147483647 -2147483647"
	run_ps_with_checker "-2147483647 -2147483648 2147483647"
	run_ps_with_checker "-2147483647 2147483647 -2147483648"
	run_ps_with_checker "-2147483647 2147483647 -2147483648"
	run_ps_with_checker "2147483647 -2147483647 -2147483648"

	run_ps_with_checker "1 2 3"
	run_ps_with_checker "2 1 3"
	run_ps_with_checker "5 0 2"
	run_ps_with_checker "2 5 0"
	run_ps_with_checker "0 5 2"
	run_ps_with_checker "3 2 1"
	run_ps_with_checker "3 1 2"

	run_ps_with_checker "1 5 2 4 3"
	run_ps_with_checker "9680 577 2599 743 4127"
	run_ps_with_checker "-2147483647 2147483647 -2147483648 0 9487 "

	run_ps_with_checker "2 1 3 6 5 8"
	run_ps_with_checker "1 2 3 5 6 8"
	run_ps_with_checker "1 2 3 5 8 6"
	run_ps_with_checker "2 1 3 6 5 10 8"

	run_ps_with_checker "-2 23 -20 39 -33 -21 -46 10 17 -13 37 -24 -35 -19 15 8 -8 \
	4 6 -44 -38 -11 -40 -22 -47 43 41 -1 29 48 28 -37 -45 11 -7 -26 30 26 -12 -14 \
	-39 3 22 31 -25 -34 -42 21 -23 49 13 27 -9 -17 32 35 16 -41 38 -3 -29 44 33 42 \
	46 -31 9 40 19 24 1 -48 2 50 18 -4 12 36 -6 45 -32 -30 14 47 -27 -5 20 -28 -49 \
	-10 0 -36 -16 -18 5 7 34 -43 -15 25"

	run_ps_with_checker "$(ruby -e "puts (1..5).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..6).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..7).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..8).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..9).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..10).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..15).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..20).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..50).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..70).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..150).to_a.shuffle.join(' ')")"
	run_ps_with_checker "$(ruby -e "puts (1..200).to_a.shuffle.join(' ')")"
	# run_ps_with_checker "$(ruby -e "puts (1..500).to_a.shuffle.join(' ')")"
	# run_ps_with_checker "$(ruby -e "puts (1..1000).to_a.shuffle.join(' ')")"
	# run_ps_with_checker "$(ruby -e "puts (1..10000).to_a.shuffle.join(' ')")"
}
run_good_stacks

################################################################################
# HUNDRED-STACK BENCHMARK
################################################################################

run_hundred_stack_benchmark() {
	hundred_stack_banner

	for i in {1..10}; do
		run_ps_with_checker "$(ruby -e "puts (-50..49).to_a.shuffle.join(' ')")"
	done
}
run_hundred_stack_benchmark

################################################################################
# FIVEHUNDRED-STACK BENCHMARK
################################################################################

run_fivehundred_stack_benchmark() {
	fivehundred_stack_banner

	for i in {1..5}; do
		run_ps_with_checker "$(ruby -e "puts (-250..249).to_a.shuffle.join(' ')")"
	done
}
run_fivehundred_stack_benchmark
