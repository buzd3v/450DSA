
#include <bits/stdc++.h>
std::map<char, char> t;

int main()
{
    t.insert(std::pair<char, char>('A', 'g'));
    t.insert(std::pair<char, char>('B', 'n'));
    t.insert(std::pair<char, char>('C', 'h'));
    t.insert(std::pair<char, char>('D', 'o'));
    t.insert(std::pair<char, char>('E', 'm'));
    t.insert(std::pair<char, char>('F', 'p'));
    t.insert(std::pair<char, char>('G', ' '));
    t.insert(std::pair<char, char>('H', 'r'));
    t.insert(std::pair<char, char>('I', 's'));
    t.insert(std::pair<char, char>('K', 'u'));
    t.insert(std::pair<char, char>('L', 'i'));
    t.insert(std::pair<char, char>('J', 't'));
    t.insert(std::pair<char, char>('M', 'k'));
    t.insert(std::pair<char, char>('N', 'v'));
    t.insert(std::pair<char, char>('O', ' '));
    t.insert(std::pair<char, char>('P', 'w'));
    t.insert(std::pair<char, char>('Q', 'x'));
    t.insert(std::pair<char, char>('R', 'f'));
    t.insert(std::pair<char, char>('S', 'l'));
    t.insert(std::pair<char, char>('T', 'y'));
    t.insert(std::pair<char, char>('U', ' '));
    t.insert(std::pair<char, char>('V', 'a'));
    t.insert(std::pair<char, char>('W', 'b'));
    t.insert(std::pair<char, char>('S', 'c'));
    t.insert(std::pair<char, char>('Y', 'd'));
    t.insert(std::pair<char, char>('Z', 'e'));
    t.insert(std::pair<char, char>('X', 'c'));

    t.insert(std::pair<char, char>(' ', ' '));

    std::string k = "YKHLBA JCZ SVIJ JZB TZVHI JCZ VHJ DR IZXKHLBA VSS RDHEI DR YVJV LBXSKYLBA YLALJVS IFZZXC CVI LEFHDNZY EVBLRDSY JCZ FHLEVHT HZVIDB RDH JCLI CVI WZZB JCZ VYNZBJ DR ELXHDZSZXJHDBLXI JCZ XDEFSZQLJT DR JCZ RKBXJLDBI JCVJ XVB BDP WZ FZHRDHEZY WT JCZ EVXCLBZ CVI HLIZB YHVEVJLXVSST VI V HXXIKSJ DR JCLI HZXZBJ YZNZXDFEZBJ LB JZXCBDSDAT EVBT DR JCZ XLFCZH ITIJZEIJCVJ PZHZ DBXZ XDBILYXHZYIZKHZ VHZBDP WHZVMVWSZ";

    for (int i = 0; i < k.length(); i++)
    {
        for (auto itr = t.begin(); itr != t.end(); ++itr)
        {
            if (k[i] == itr->first)
            {
                k[i] = itr->second;
            }
        }
    }
    std::cout << k;
}