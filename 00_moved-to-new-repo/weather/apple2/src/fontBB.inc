 .byte   $10,$08,$36,$7F,$3F,$3F,$7E,$36 ;'@'^
    .byte   $10,$08,$36,$41,$21,$21,$4A,$36 ;'A'^
    .byte   $00,$00,$02,$06,$0E,$1E,$36,$42 ;'B'^
    .byte   $7F,$22,$14,$08,$08,$14,$2A,$7F ;'C'^
    .byte   $00,$40,$20,$11,$0A,$04,$04,$00 ;'D'^
    .byte   $7F,$3F,$5F,$6C,$75,$7B,$7B,$7F ;'E'^
    .byte   $70,$60,$7E,$31,$79,$30,$3F,$02 ;'F'^
    .byte   $00,$18,$07,$00,$07,$0C,$08,$70 ;'G'^
    .byte   $08,$04,$02,$7F,$02,$04,$08,$00 ;'H'^
    .byte   $00,$00,$00,$00,$00,$00,$00,$2A ;'I'^
    .byte   $08,$08,$08,$08,$49,$2A,$1C,$08 ;'J'^
    .byte   $08,$1C,$2A,$49,$08,$08,$08,$08 ;'K'^
    .byte   $7F,$00,$00,$00,$00,$00,$00,$00 ;'L'^
    .byte   $40,$40,$40,$44,$46,$7F,$06,$04 ;'M'^
    .byte   $3F,$3F,$3F,$3F,$3F,$3F,$3F,$3F ;'N'^
    .byte   $13,$18,$1C,$7E,$1C,$18,$10,$6F ;'O'^
    .byte   $64,$0C,$1C,$3F,$1C,$0C,$04,$7B ;'P'^
    .byte   $40,$48,$08,$7F,$3E,$1C,$48,$40 ;'Q'^
    .byte   $40,$48,$1C,$3E,$7E,$08,$48,$40 ;'R'^
    .byte   $00,$00,$00,$7F,$00,$00,$00,$00 ;'S'^
    .byte   $01,$01,$01,$01,$01,$01,$01,$7F ;'T'^
    .byte   $08,$10,$20,$7F,$20,$10,$08,$00 ;'U'^
    .byte   $2A,$55,$2A,$55,$2A,$55,$2A,$55 ;'V'^
    .byte   $55,$2A,$55,$2A,$55,$2A,$55,$2A ;'W'^
    .byte   $00,$3E,$41,$01,$01,$01,$7F,$00 ;'X'^
    .byte   $00,$00,$3F,$40,$40,$40,$7F,$00 ;'Y'^
    .byte   $40,$40,$40,$40,$40,$40,$40,$40 ;'Z'^
    .byte   $08,$1C,$3E,$7F,$3E,$1C,$08,$00 ;'['^
    .byte   $7F,$00,$00,$00,$00,$00,$00,$7F ;'\'^
    .byte   $14,$14,$77,$00,$77,$14,$14,$00 ;']'^
    .byte   $7F,$40,$40,$4C,$4C,$40,$40,$7F ;'^'^
    .byte   $01,$01,$01,$01,$01,$01,$01,$01 ;'_'^
	.byte $80,$80,$80,$80,$80,$80,$80,$80 ; No= 0 space
	.byte $87,$87,$87,$87,$80,$87,$87,$80 ; No= 1 ! 
 	.byte   $00,$1c,$33,$1c,$00,$00,$00,$00 ;'degree
;	.byte $b6,$b6,$a4,$b6,$80,$80,$80,$80 ; No= 2 
	.byte $00,$c0,$c0,$c0,$d4,$d0,$c0,$ff ; min 1 (shift 3)
	.byte $00,$82,$82,$82,$aa,$8a,$82,$ff ; min 2 (shift 4)
;	.byte $9e,$9e,$bf,$9e,$bf,$9e,$9e,$80 ; No= 3
;	.byte $8c,$be,$83,$9e,$b0,$9f,$8c,$80 ; No= 4
	.byte $b7,$b7,$98,$8c,$86,$bb,$bb,$80 ; No= 5 %
	.byte $ff,$a0,$a8,$aa,$a0,$a0,$a0,$00 ; max 1 (shift 6)
	.byte $ff,$81,$85,$95,$81,$81,$81,$00 ; max 2 (shift 7)
;	.byte $86,$8f,$86,$8f,$bb,$9b,$ae,$80 ; No= 6
;	.byte $8c,$8c,$88,$8c,$80,$80,$80,$80 ; No= 7
	.byte $b8,$9c,$8e,$8e,$8e,$9c,$b8,$80 ; No= 8
	.byte $87,$8e,$9c,$9c,$9c,$8e,$87,$80 ; No= 9
	.byte $88,$aa,$9c,$be,$9c,$aa,$88,$80 ; No=10
	.byte $8c,$8c,$bf,$bf,$8c,$8c,$80,$80 ; No=11
	.byte $80,$80,$80,$80,$80,$87,$86,$83 ; No=12
	.byte $80,$80,$be,$be,$80,$80,$80,$80 ; No=13
	.byte $80,$80,$80,$80,$80,$87,$87,$80 ; No=14
	.byte $e0,$f0,$b8,$9c,$8e,$87,$83,$80 ; No=15
	.byte $9e,$b3,$b3,$b3,$b3,$b3,$9e,$80 ; No=16
	.byte $8c,$8e,$8f,$8c,$8c,$8c,$bf,$80 ; No=17
	.byte $9e,$bf,$b3,$b8,$8e,$bf,$bf,$80 ; No=18
	.byte $9e,$bf,$b0,$be,$b0,$bf,$9e,$80 ; No=19
	.byte $b8,$bc,$b6,$b3,$bf,$b0,$b0,$80 ; No=20
	.byte $bf,$bf,$83,$9f,$b0,$bf,$9e,$80 ; No=21
	.byte $9e,$bf,$83,$9f,$b3,$bf,$9e,$80 ; No=22
	.byte $bf,$bf,$b0,$98,$8c,$8c,$8c,$80 ; No=23
	.byte $9e,$bf,$b3,$9e,$b3,$bf,$9e,$80 ; No=24
	.byte $9e,$bf,$b3,$be,$b0,$bf,$9e,$80 ; No=25
	.byte $80,$9c,$9c,$80,$80,$9c,$9c,$80 ; No=26
	.byte $80,$87,$87,$80,$80,$87,$86,$83 ; No=27
	.byte $f0,$b8,$9c,$8e,$9c,$b8,$f0,$80 ; No=28
	.byte $80,$80,$be,$80,$be,$80,$80,$80 ; No=29
	.byte $87,$8e,$9c,$b8,$9c,$8e,$87,$80 ; No=30
	.byte $9e,$bf,$b3,$98,$8c,$80,$8c,$80 ; No=31
	.byte $9e,$b3,$b3,$bb,$bb,$83,$be,$80 ; No=32
	.byte $9e,$bf,$b3,$bf,$bf,$b3,$b3,$80 ; No=33
	.byte $9f,$bf,$b3,$9f,$b3,$bf,$9f,$80 ; No=34
	.byte $9e,$bf,$b3,$83,$b3,$bf,$9e,$80 ; No=35
	.byte $9f,$bf,$b3,$b3,$b3,$bf,$9f,$80 ; No=36
	.byte $bf,$bf,$83,$9f,$83,$bf,$bf,$80 ; No=37
	.byte $bf,$bf,$83,$9f,$9f,$83,$83,$80 ; No=38
	.byte $9e,$bf,$83,$bb,$b3,$bf,$9e,$80 ; No=39
	.byte $b3,$b3,$b3,$bf,$bf,$b3,$b3,$80 ; No=40
	.byte $bf,$bf,$8c,$8c,$8c,$bf,$bf,$80 ; No=41
	.byte $b0,$b0,$b0,$b0,$b3,$bf,$9e,$80 ; No=42
	.byte $b3,$bb,$9f,$8f,$9f,$bb,$b3,$80 ; No=43
	.byte $83,$83,$83,$83,$83,$bf,$bf,$80 ; No=44
	.byte $b3,$bf,$b3,$b3,$b3,$b3,$b3,$80 ; No=45
	.byte $b3,$b3,$b7,$bf,$bb,$b3,$b3,$80 ; No=46
	.byte $9e,$bf,$b3,$b3,$b3,$bf,$9e,$80 ; No=47
	.byte $9f,$bf,$b3,$bf,$9f,$83,$83,$80 ; No=48
	.byte $9e,$bf,$a3,$a3,$ab,$93,$ae,$80 ; No=49
	.byte $9f,$bf,$b3,$bf,$9f,$bb,$b3,$80 ; No=50
	.byte $9e,$b3,$83,$9e,$b0,$b3,$9e,$80 ; No=51
	.byte $bf,$bf,$8c,$8c,$8c,$8c,$8c,$80 ; No=52
	.byte $b3,$b3,$b3,$b3,$b3,$bf,$9e,$80 ; No=53
	.byte $b3,$b3,$b3,$b3,$b3,$9e,$8c,$80 ; No=54
	.byte $b3,$b3,$b3,$b3,$b3,$bf,$b3,$80 ; No=55
	.byte $b3,$b3,$9e,$8c,$9e,$b3,$b3,$80 ; No=56
	.byte $b3,$b3,$b3,$9e,$8c,$8c,$8c,$80 ; No=57
	.byte $bf,$bf,$98,$8c,$86,$bf,$bf,$80 ; No=58
	.byte $bc,$bc,$8c,$8c,$8c,$bc,$bc,$80 ; No=59
	.byte $83,$87,$8e,$9c,$b8,$f0,$e0,$80 ; No=60
	.byte $8f,$8f,$8c,$8c,$8c,$8f,$8f,$80 ; No=61
	.byte $8c,$9e,$bf,$80,$80,$80,$80,$80 ; No=62
	.byte $80,$80,$80,$80,$80,$ff,$ff,$80 ; No=63
	.byte $86,$8c,$98,$80,$80,$80,$80,$80 ; No=64
	.byte $80,$80,$9e,$b0,$be,$b3,$be,$80 ; No=65
	.byte $83,$83,$9f,$b3,$b3,$b3,$9f,$80 ; No=66
	.byte $80,$80,$9e,$b3,$83,$b3,$9e,$80 ; No=67
	.byte $b0,$b0,$be,$b3,$b3,$b3,$be,$80 ; No=68
	.byte $80,$80,$9e,$b3,$9f,$83,$9e,$80 ; No=69
	.byte $9c,$b6,$86,$9f,$86,$86,$86,$80 ; No=70
	.byte $80,$80,$9e,$b3,$b3,$be,$b0,$9e ; No=71
	.byte $83,$83,$9f,$b3,$b3,$b3,$b3,$80 ; No=72
	.byte $80,$8c,$80,$8c,$8c,$8c,$8c,$80 ; No=73
	.byte $b0,$80,$b0,$b0,$b0,$b3,$b3,$9e ; No=74
	.byte $83,$83,$b3,$9b,$8f,$9b,$b3,$80 ; No=75
	.byte $8e,$8c,$8c,$8c,$8c,$8c,$9e,$80 ; No=76
	.byte $80,$80,$b3,$bf,$b3,$b3,$b3,$80 ; No=77
	.byte $80,$80,$9f,$b3,$b3,$b3,$b3,$80 ; No=78
	.byte $80,$80,$9e,$b3,$b3,$b3,$9e,$80 ; No=79
	.byte $80,$80,$9f,$b3,$b3,$9f,$83,$83 ; No=80
	.byte $80,$80,$be,$b3,$b3,$be,$b0,$b0 ; No=81
	.byte $80,$80,$9f,$b3,$83,$83,$83,$80 ; No=82
	.byte $80,$80,$9e,$83,$9e,$b0,$9e,$80 ; No=83
	.byte $86,$86,$9f,$86,$86,$b6,$9c,$80 ; No=84
	.byte $80,$80,$b3,$b3,$b3,$b3,$be,$80 ; No=85
	.byte $80,$80,$b3,$b3,$b3,$9e,$8c,$80 ; No=86
	.byte $80,$80,$b3,$b3,$b3,$bf,$b3,$80 ; No=87
	.byte $80,$80,$b3,$9e,$8c,$9e,$b3,$80 ; No=88
	.byte $80,$80,$b3,$b3,$b3,$be,$b0,$9e ; No=89
	.byte $80,$80,$bf,$98,$8c,$86,$bf,$80 ; No=90
	.byte $9c,$9e,$86,$87,$86,$9e,$9c,$80 ; No=91
	.byte $8c,$8c,$8c,$8c,$8c,$8c,$8c,$8c ; No=92
	.byte $8e,$9e,$98,$b8,$98,$9e,$8e,$80 ; No=93
	.byte $86,$bf,$98,$80,$80,$80,$80,$80 ; No=94