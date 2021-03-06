; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strclr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:26:25 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strclr

extern _ft_strlen
extern _ft_bzero

section .text

_ft_strclr:
	push rdi
	cmp rdi, 0
	je end
	call _ft_strlen
	mov rsi, rax
	call _ft_bzero
	; cld
	; rep stosb

end:
	pop rdi
	ret
