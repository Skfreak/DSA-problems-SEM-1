public int mingap(Node root , int x , int y)
    {
        int mingap = Integer.MAX_VALUE;

        if(y < root.data) return mingap(root.left,x,y);

        else if(x > root.data) return mingap(root.right,x,y);

        else if(x <= root.data && y >= root.data)
        {
            Node t = root;

            while( t != null )
            {
                if(x < t.data)
                {
                    mingap = Math.min(mingap,t.data - t.left.max);
                    t = t.left;
                }

                else if( x > t.data )
                {

                    t = t.right;
                }

                else
                {

                    if(t.right != null) {
                        mingap = Math.min(mingap,t.right.min - t.data);
                    }
                    mingap = Math.min(mingap,getMingap(t.right));
                    break;
                }
            }

            t = root;

            while(t != null)
            {
                if(y > t.data)
                {
                    mingap = Math.min(mingap,t.right.min - t.data);
                    t = t.right;
                }

                else if( y < t.data)
                {
                    t = t.left;
                }

                else
                {
                    if(t.left!= null)
                    {
                        mingap = Math.min(mingap,t.data-t.left.max);
                    }

                    mingap = Math.min(mingap,getMingap(t.left));
                    break;
                }
            }
        }

        return mingap;

    }
}
