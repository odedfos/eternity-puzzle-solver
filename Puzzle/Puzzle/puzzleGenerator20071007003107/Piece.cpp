#include "Piece.h"

Piece::Piece(int id, Shape top, Shape right, Shape bottom, Shape left)
{
	m_ID = id;
	m_ShapeVec.push_back(top);
	m_ShapeVec.push_back(right);
	m_ShapeVec.push_back(bottom);
	m_ShapeVec.push_back(left);
	m_Rotation = 0;
}

Piece::~Piece(void)
{}

void Piece::printPiece()
{
	printf("Piece: %d -> { %d, %d, %d, %d} Rotation: %d\n", m_ID, m_ShapeVec.at(TOP), m_ShapeVec.at(RIGHT), m_ShapeVec.at(BOTTOM), m_ShapeVec.at(LEFT), m_Rotation);
}

void Piece::rotateRight() {m_Rotation = (m_Rotation - 1 + 4) % 4;}

Shape Piece::getTop() {return m_ShapeVec.at((TOP + m_Rotation) % 4);}

Shape Piece::getRight(){return m_ShapeVec.at((RIGHT + m_Rotation) % 4);}

Shape Piece::getBottom(){return m_ShapeVec.at((BOTTOM + m_Rotation) % 4);}

Shape Piece::getLeft(){return m_ShapeVec.at((LEFT + m_Rotation) % 4);}

bool Piece::tryToMatchPiece(Shape top, Shape right, Shape bottom, Shape left)
{
	for (int i = 0; i < 4; i++)
	{
		if ((top == NONE) || (top == getTop()))
			if ((right == NONE) || (right == getRight()))
				if ((bottom == NONE) || (bottom == getBottom()))
					if ((left == NONE) || (left == getLeft()))
						return true;
		rotateRight();
	}
	return false;
}


Piece** Piece::PieceGenerator()
{
	Piece** puzzlePieces = (Piece**)malloc(257 * sizeof(void*));
	puzzlePieces[0] = new Piece(0, NONE, NONE, NONE, NONE);
	puzzlePieces[1] = new Piece(1, WB, JB, TD, TD);
	puzzlePieces[2] = new Piece(2, WB, OD, TD, TD);
	puzzlePieces[3] = new Piece(3, FY, JB, TD, TD);
	puzzlePieces[4] = new Piece(4, JB, FY, TD, TD);
	puzzlePieces[5] = new Piece(5, BY, WB, TD, WB);
	puzzlePieces[6] = new Piece(6, AB, FY, TD, WB);
	puzzlePieces[7] = new Piece(7, PP, WB, TD, WB);
	puzzlePieces[8] = new Piece(8, PP, KO, TD, WB);
	puzzlePieces[9] = new Piece(9, AO, JB, TD, WB);
	puzzlePieces[10] = new Piece(10, CH, OD, TD, WB);
	puzzlePieces[11] = new Piece(11, QG, FY, TD, WB);
	puzzlePieces[12] = new Piece(12, BO, OD, TD, WB);
	puzzlePieces[13] = new Piece(13, BO, KO, TD, WB);
	puzzlePieces[14] = new Piece(14, CY, OD, TD, WB);
	puzzlePieces[15] = new Piece(15, AB, WB, TD, FY);
	puzzlePieces[16] = new Piece(16, SB, JB, TD, FY);
	puzzlePieces[17] = new Piece(17, BH, KO, TD, FY);
	puzzlePieces[18] = new Piece(18, SY, KO, TD, FY);
	puzzlePieces[19] = new Piece(19, CH, FY, TD, FY);
	puzzlePieces[20] = new Piece(20, QG, FY, TD, FY);
	puzzlePieces[21] = new Piece(21, AH, OD, TD, FY);
	puzzlePieces[22] = new Piece(22, CD, WB, TD, FY);
	puzzlePieces[23] = new Piece(23, CD, KO, TD, FY);
	puzzlePieces[24] = new Piece(24, SP, WB, TD, FY);
	puzzlePieces[25] = new Piece(25, CY, WB, TD, FY);
	puzzlePieces[26] = new Piece(26, BY, FY, TD, JB);
	puzzlePieces[27] = new Piece(27, BY, JB, TD, JB);
	puzzlePieces[28] = new Piece(28, AB, JB, TD, JB);
	puzzlePieces[29] = new Piece(29, SB, JB, TD, JB);
	puzzlePieces[30] = new Piece(30, CH, KO, TD, JB);
	puzzlePieces[31] = new Piece(31, QG, FY, TD, JB);
	puzzlePieces[32] = new Piece(32, SP, JB, TD, JB);
	puzzlePieces[33] = new Piece(33, BO, FY, TD, JB);
	puzzlePieces[34] = new Piece(34, BO, OD, TD, JB);
	puzzlePieces[35] = new Piece(35, QB, KO, TD, JB);
	puzzlePieces[36] = new Piece(36, PD, OD, TD, JB);
	puzzlePieces[37] = new Piece(37, SB, WB, TD, OD);
	puzzlePieces[38] = new Piece(38, PB, KO, TD, OD);
	puzzlePieces[39] = new Piece(39, AO, KO, TD, OD);
	puzzlePieces[40] = new Piece(40, SY, FY, TD, OD);
	puzzlePieces[41] = new Piece(41, SY, JB, TD, OD);
	puzzlePieces[42] = new Piece(42, QG, WB, TD, OD);
	puzzlePieces[43] = new Piece(43, QG, FY, TD, OD);
	puzzlePieces[44] = new Piece(44, QG, JB, TD, OD);
	puzzlePieces[45] = new Piece(45, AH, WB, TD, OD);
	puzzlePieces[46] = new Piece(46, SP, OD, TD, OD);
	puzzlePieces[47] = new Piece(47, BO, OD, TD, OD);
	puzzlePieces[48] = new Piece(48, QB, OD, TD, OD);
	puzzlePieces[49] = new Piece(49, BY, KO, TD, KO);
	puzzlePieces[50] = new Piece(50, AB, WB, TD, KO);
	puzzlePieces[51] = new Piece(51, AB, FY, TD, KO);
	puzzlePieces[52] = new Piece(52, PP, WB, TD, KO);
	puzzlePieces[53] = new Piece(53, CH, OD, TD, KO);
	puzzlePieces[54] = new Piece(54, AH, OD, TD, KO);
	puzzlePieces[55] = new Piece(55, AH, KO, TD, KO);
	puzzlePieces[56] = new Piece(56, BO, JB, TD, KO);
	puzzlePieces[57] = new Piece(57, QB, WB, TD, KO);
	puzzlePieces[58] = new Piece(58, QB, KO, TD, KO);
	puzzlePieces[59] = new Piece(59, CY, FY, TD, KO);
	puzzlePieces[60] = new Piece(60, PD, JB, TD, KO);
	puzzlePieces[61] = new Piece(61, PP, SB, BY, BY);
	puzzlePieces[62] = new Piece(62, BH, CH, BY, BY);
	puzzlePieces[63] = new Piece(63, AB, PB, BY, AB);
	puzzlePieces[64] = new Piece(64, BY, BO, BY, SB);
	puzzlePieces[65] = new Piece(65, SB, PD, BY, SB);
	puzzlePieces[66] = new Piece(66, BH, BH, BY, SB);
	puzzlePieces[67] = new Piece(67, AO, AB, BY, SB);
	puzzlePieces[68] = new Piece(68, SP, PP, BY, SB);
	puzzlePieces[69] = new Piece(69, PD, BO, BY, SB);
	puzzlePieces[70] = new Piece(70, PB, CH, BY, PB);
	puzzlePieces[71] = new Piece(71, CH, CD, BY, PB);
	puzzlePieces[72] = new Piece(72, BH, SB, BY, AO);
	puzzlePieces[73] = new Piece(73, QG, AH, BY, AO);
	puzzlePieces[74] = new Piece(74, SP, QG, BY, AO);
	puzzlePieces[75] = new Piece(75, BO, PB, BY, AO);
	puzzlePieces[76] = new Piece(76, BH, QG, BY, SY);
	puzzlePieces[77] = new Piece(77, SY, QG, BY, SY);
	puzzlePieces[78] = new Piece(78, PB, QB, BY, CH);
	puzzlePieces[79] = new Piece(79, SP, PB, BY, CH);
	puzzlePieces[80] = new Piece(80, QB, CY, BY, CH);
	puzzlePieces[81] = new Piece(81, SY, SB, BY, QG);
	puzzlePieces[82] = new Piece(82, SB, SB, BY, AH);
	puzzlePieces[83] = new Piece(83, AO, AH, BY, AH);
	puzzlePieces[84] = new Piece(84, SB, SY, BY, CD);
	puzzlePieces[85] = new Piece(85, PP, BH, BY, CD);
	puzzlePieces[86] = new Piece(86, BO, CD, BY, CD);
	puzzlePieces[87] = new Piece(87, QB, SP, BY, CD);
	puzzlePieces[88] = new Piece(88, BY, CY, BY, SP);
	puzzlePieces[89] = new Piece(89, PP, PD, BY, SP);
	puzzlePieces[90] = new Piece(90, AH, QB, BY, SP);
	puzzlePieces[91] = new Piece(91, AO, CD, BY, BO);
	puzzlePieces[92] = new Piece(92, SY, QG, BY, BO);
	puzzlePieces[93] = new Piece(93, SY, AH, BY, BO);
	puzzlePieces[94] = new Piece(94, AH, CY, BY, BO);
	puzzlePieces[95] = new Piece(95, CD, BH, BY, BO);
	puzzlePieces[96] = new Piece(96, CY, PB, BY, CY);
	puzzlePieces[97] = new Piece(97, AH, SY, BY, PD);
	puzzlePieces[98] = new Piece(98, SP, BO, BY, PD);
	puzzlePieces[99] = new Piece(99, CY, PP, BY, PD);
	puzzlePieces[100] = new Piece(100, PD, CY, BY, PD);
	puzzlePieces[101] = new Piece(101, CD, QG, AB, AB);
	puzzlePieces[102] = new Piece(102, CD, QB, AB, AB);
	puzzlePieces[103] = new Piece(103, QB, SY, AB, AB);
	puzzlePieces[104] = new Piece(104, PD, PP, AB, AB);
	puzzlePieces[105] = new Piece(105, AH, QG, AB, SB);
	puzzlePieces[106] = new Piece(106, PB, BO, AB, PP);
	puzzlePieces[107] = new Piece(107, SY, BO, AB, PP);
	puzzlePieces[108] = new Piece(108, AH, QG, AB, PP);
	puzzlePieces[109] = new Piece(109, QB, AO, AB, PP);
	puzzlePieces[110] = new Piece(110, QG, CD, AB, BH);
	puzzlePieces[111] = new Piece(111, CD, QG, AB, BH);
	puzzlePieces[112] = new Piece(112, SP, SY, AB, PB);
	puzzlePieces[113] = new Piece(113, SP, QB, AB, PB);
	puzzlePieces[114] = new Piece(114, BH, AH, AB, AO);
	puzzlePieces[115] = new Piece(115, CH, CD, AB, AO);
	puzzlePieces[116] = new Piece(116, CD, AO, AB, AO);
	puzzlePieces[117] = new Piece(117, PD, QB, AB, AO);
	puzzlePieces[118] = new Piece(118, PB, CY, AB, SY);
	puzzlePieces[119] = new Piece(119, QB, CD, AB, CH);
	puzzlePieces[120] = new Piece(120, BO, PD, AB, QG);
	puzzlePieces[121] = new Piece(121, BH, PD, AB, AH);
	puzzlePieces[122] = new Piece(122, PP, QB, AB, SP);
	puzzlePieces[123] = new Piece(123, BH, SY, AB, SP);
	puzzlePieces[124] = new Piece(124, SP, QG, AB, SP);
	puzzlePieces[125] = new Piece(125, CD, PD, AB, BO);
	puzzlePieces[126] = new Piece(126, CY, QG, AB, BO);
	puzzlePieces[127] = new Piece(127, BH, PP, AB, QB);
	puzzlePieces[128] = new Piece(128, SY, CY, AB, QB);
	puzzlePieces[129] = new Piece(129, AH, PB, AB, QB);
	puzzlePieces[130] = new Piece(130, SP, BO, AB, QB);
	puzzlePieces[131] = new Piece(131, PP, SP, AB, CY);
	puzzlePieces[132] = new Piece(132, CD, BH, AB, CY);
	puzzlePieces[133] = new Piece(133, BH, QB, AB, PD);
	puzzlePieces[134] = new Piece(134, AO, AH, AB, PD);
	puzzlePieces[135] = new Piece(135, AH, PB, AB, PD);
	puzzlePieces[136] = new Piece(136, QB, SP, AB, PD);
	puzzlePieces[137] = new Piece(137, SP, CH, SB, SB);
	puzzlePieces[138] = new Piece(138, PP, PB, SB, PP);
	puzzlePieces[139] = new Piece(139, PP, AO, SB, PP);
	puzzlePieces[140] = new Piece(140, PP, CD, SB, PP);
	puzzlePieces[141] = new Piece(141, SY, CY, SB, PP);
	puzzlePieces[142] = new Piece(142, QG, PP, SB, PP);
	puzzlePieces[143] = new Piece(143, QB, CD, SB, PP);
	puzzlePieces[144] = new Piece(144, CY, CY, SB, PP);
	puzzlePieces[145] = new Piece(145, PB, AH, SB, BH);
	puzzlePieces[146] = new Piece(146, SB, CD, SB, PB);
	puzzlePieces[147] = new Piece(147, SB, PD, SB, PB);
	puzzlePieces[148] = new Piece(148, PB, BH, SB, PB);
	puzzlePieces[149] = new Piece(149, QG, CD, SB, PB);
	puzzlePieces[150] = new Piece(150, PP, AO, SB, SY);
	puzzlePieces[151] = new Piece(151, AH, PD, SB, SY);
	puzzlePieces[152] = new Piece(152, AO, AO, SB, CH);
	puzzlePieces[153] = new Piece(153, AO, SY, SB, CH);
	puzzlePieces[154] = new Piece(154, PD, QB, SB, CH);
	puzzlePieces[155] = new Piece(155, CH, CH, SB, AH);
	puzzlePieces[156] = new Piece(156, CH, CD, SB, AH);
	puzzlePieces[157] = new Piece(157, PD, CH, SB, AH);
	puzzlePieces[158] = new Piece(158, CH, QB, SB, SP);
	puzzlePieces[159] = new Piece(159, BO, PP, SB, SP);
	puzzlePieces[160] = new Piece(160, CY, CY, SB, BO);
	puzzlePieces[161] = new Piece(161, PP, SP, SB, QB);
	puzzlePieces[162] = new Piece(162, BH, SP, SB, QB);
	puzzlePieces[163] = new Piece(163, QG, AO, SB, PD);
	puzzlePieces[164] = new Piece(164, AH, QB, SB, PD);
	puzzlePieces[165] = new Piece(165, PB, AH, PP, BH);
	puzzlePieces[166] = new Piece(166, AH, BO, PP, BH);
	puzzlePieces[167] = new Piece(167, PB, PB, PP, AO);
	puzzlePieces[168] = new Piece(168, AO, QG, PP, SY);
	puzzlePieces[169] = new Piece(169, SY, CY, PP, SY);
	puzzlePieces[170] = new Piece(170, AH, BO, PP, CH);
	puzzlePieces[171] = new Piece(171, SP, QB, PP, CH);
	puzzlePieces[172] = new Piece(172, CY, AO, PP, CH);
	puzzlePieces[173] = new Piece(173, QG, QG, PP, QG);
	puzzlePieces[174] = new Piece(174, CD, SP, PP, QG);
	puzzlePieces[175] = new Piece(175, CH, CY, PP, AH);
	puzzlePieces[176] = new Piece(176, CH, SY, PP, CD);
	puzzlePieces[177] = new Piece(177, BH, AH, PP, SP);
	puzzlePieces[178] = new Piece(178, CD, QB, PP, BO);
	puzzlePieces[179] = new Piece(179, BO, QG, PP, BO);
	puzzlePieces[180] = new Piece(180, CH, QB, PP, QB);
	puzzlePieces[181] = new Piece(181, AO, QB, PP, CY);
	puzzlePieces[182] = new Piece(182, CH, AO, PP, CY);
	puzzlePieces[183] = new Piece(183, SY, BO, BH, BH);
	puzzlePieces[184] = new Piece(184, PD, CH, BH, PB);
	puzzlePieces[185] = new Piece(185, SY, CD, BH, AO);
	puzzlePieces[186] = new Piece(186, BO, BO, BH, AO);
	puzzlePieces[187] = new Piece(187, CY, CH, BH, SY);
	puzzlePieces[188] = new Piece(188, BH, CY, BH, CH);
	puzzlePieces[189] = new Piece(189, PB, SY, BH, CH);
	puzzlePieces[190] = new Piece(190, QB, SY, BH, CH);
	puzzlePieces[191] = new Piece(191, PB, PB, BH, QG);
	puzzlePieces[192] = new Piece(192, QG, SP, BH, QG);
	puzzlePieces[193] = new Piece(193, AO, CH, BH, AH);
	puzzlePieces[194] = new Piece(194, CY, AO, BH, CD);
	puzzlePieces[195] = new Piece(195, CY, PD, BH, CD);
	puzzlePieces[196] = new Piece(196, PD, QG, BH, CD);
	puzzlePieces[197] = new Piece(197, AO, PD, BH, SP);
	puzzlePieces[198] = new Piece(198, SY, BO, BH, SP);
	puzzlePieces[199] = new Piece(199, SP, SP, BH, SP);
	puzzlePieces[200] = new Piece(200, SY, PB, BH, BO);
	puzzlePieces[201] = new Piece(201, CY, BO, BH, QB);
	puzzlePieces[202] = new Piece(202, PD, CH, BH, QB);
	puzzlePieces[203] = new Piece(203, CD, SY, BH, CY);
	puzzlePieces[204] = new Piece(204, CD, BO, BH, CY);
	puzzlePieces[205] = new Piece(205, QB, PB, BH, CY);
	puzzlePieces[206] = new Piece(206, PD, CY, BH, CY);
	puzzlePieces[207] = new Piece(207, PD, CH, PB, PB);
	puzzlePieces[208] = new Piece(208, SY, PD, PB, AO);
	puzzlePieces[209] = new Piece(209, BO, QG, PB, AO);
	puzzlePieces[210] = new Piece(210, AO, SY, PB, CH);
	puzzlePieces[211] = new Piece(211, QB, QG, PB, CH);
	puzzlePieces[212] = new Piece(212, PB, QB, PB, QG);
	puzzlePieces[213] = new Piece(213, BO, BO, PB, AH);
	puzzlePieces[214] = new Piece(214, PB, SP, PB, CD);
	puzzlePieces[215] = new Piece(215, AH, PD, PB, CD);
	puzzlePieces[216] = new Piece(216, PD, CY, PB, CD);
	puzzlePieces[217] = new Piece(217, SY, QG, PB, SP);
	puzzlePieces[218] = new Piece(218, AH, CD, PB, QB);
	puzzlePieces[219] = new Piece(219, AO, AH, PB, CY);
	puzzlePieces[220] = new Piece(220, AO, QB, PB, PD);
	puzzlePieces[221] = new Piece(221, CY, CY, PB, PD);
	puzzlePieces[222] = new Piece(222, CY, PD, PB, PD);
	puzzlePieces[223] = new Piece(223, CD, PD, AO, AO);
	puzzlePieces[224] = new Piece(224, SP, CH, AO, AO);
	puzzlePieces[225] = new Piece(225, QB, QG, AO, AO);
	puzzlePieces[226] = new Piece(226, SY, QG, AO, CH);
	puzzlePieces[227] = new Piece(227, CD, CD, AO, CH);
	puzzlePieces[228] = new Piece(228, SY, BO, AO, AH);
	puzzlePieces[229] = new Piece(229, CH, PD, AO, SP);
	puzzlePieces[230] = new Piece(230, QB, BO, AO, SP);
	puzzlePieces[231] = new Piece(231, CD, SP, AO, BO);
	puzzlePieces[232] = new Piece(232, CD, CY, AO, BO);
	puzzlePieces[233] = new Piece(233, SY, SP, SY, SY);
	puzzlePieces[234] = new Piece(234, QB, AH, SY, CH);
	puzzlePieces[235] = new Piece(235, CH, AH, SY, AH);
	puzzlePieces[236] = new Piece(236, CH, SP, SY, AH);
	puzzlePieces[237] = new Piece(237, CD, QG, SY, AH);
	puzzlePieces[238] = new Piece(238, AH, QB, SY, CD);
	puzzlePieces[239] = new Piece(239, QG, PD, SY, SP);
	puzzlePieces[240] = new Piece(240, CY, QG, SY, SP);
	puzzlePieces[241] = new Piece(241, CH, CY, SY, BO);
	puzzlePieces[242] = new Piece(242, AH, CY, SY, BO);
	puzzlePieces[243] = new Piece(243, QG, CD, CH, QG);
	puzzlePieces[244] = new Piece(244, SP, BO, CH, QG);
	puzzlePieces[245] = new Piece(245, PD, SP, CH, AH);
	puzzlePieces[246] = new Piece(246, QB, PD, CH, CY);
	puzzlePieces[247] = new Piece(247, CY, PD, QG, QG);
	puzzlePieces[248] = new Piece(248, CD, AH, QG, AH);
	puzzlePieces[249] = new Piece(249, AH, CY, QG, CD);
	puzzlePieces[250] = new Piece(250, QB, CY, QG, SP);
	puzzlePieces[251] = new Piece(251, PD, BO, AH, AH);
	puzzlePieces[252] = new Piece(252, BO, CD, AH, CD);
	puzzlePieces[253] = new Piece(253, QB, SP, CD, BO);
	puzzlePieces[254] = new Piece(254, CY, QB, SP, QB);
	puzzlePieces[255] = new Piece(255, QB, PD, SP, PD);
	puzzlePieces[256] = new Piece(256, CY, PD, BO, PD);

	return puzzlePieces;
}


