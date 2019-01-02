int main()
{
    vector<string> str;
    string word;

    while (cin >> word) {
        if (word[0] == '0')
            break;
        str.push_back(word);
    }

    cout << str[0] << str[1] << str[2] << endl;
    for (auto index : str)
       cout << index;

    return 0;
}
