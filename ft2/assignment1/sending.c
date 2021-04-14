while ((ch = getchar()) != EOF)
    {
        if (ch != '\t')
        {

            if (is_newline)
            {

                char *chr = (char *)malloc(sizeof(char) * 1024);
                int i = 0;
                chr[i++] = ch;
                while ((ch = getchar()) != '\n')
                {
                    chr[i++] = ch;
                }
                add_node(flag, chr);
            }
            flag = 0;
        }
        else if (ch == '\n')
        {
            is_newline = ch == '\n';
        }
        else
        {
            ++flag;
        }

    }
