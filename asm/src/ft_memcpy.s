; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:25:28 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memcpy

section .text

_ft_memcpy:
	push rdi
	cmp rdi, 0
	je exit
	cmp rsi, 0
	je exit
	cmp rdx, 0
	jle exit
	lea rax, [rsi]
	mov rcx, rdx
	rep movsb

exit:
	pop rax
	ret
