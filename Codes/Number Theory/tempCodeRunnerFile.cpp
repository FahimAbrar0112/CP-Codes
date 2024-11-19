

    for(int i=1;i<N;i++)
    {
        for(int j=i;j<N;j+=i)
        {
            multiples_ct[i]+=hsh[j];

        }
    }