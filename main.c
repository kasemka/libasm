#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>



extern size_t ft_strlen(const char *str);
extern size_t ft_strcpy(char *des, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern size_t ft_write(int fd, const void *buf, size_t nbyte);
extern size_t ft_read(int fd, const void *buf, size_t nbyte);
extern char * ft_strdup( const char *str1 );

int main() {

/*
 * ft_strlen
 */	
    printf("\ntest 1, strlen with 0:\n");
    const char *msg = "";
    printf("strlen %zu\n", strlen(msg));  
    printf("strlen: %zu\n", ft_strlen(msg));  

    printf("\ntest 2, strlen with long text:\n");
    const char *msg2 = "Lorem ipsum odor amet, consectetuer adipiscing elit. Dictum dui adipiscing sapien facilisi at nascetur mauris. Ullamcorper et etiam ligula turpis mollis. Lobortis praesent convallis aliquet; lacus dignissim netus. Curabitur rutrum aliquam tincidunt suscipit malesuada commodo convallis. Nascetur scelerisque sodales ornare ullamcorper nisl risus proin. Enim mus odio; conubia pretium inceptos nunc. Class per at in maximus class; ac cras platea. Proin non maximus tincidunt maecenas nunc; porttitor molestie vivamus litora. Vel praesent magna ornare pellentesque iaculis eget orci. Et fringilla accumsan nostra hendrerit, habitant fames porttitor mus. Bibendum ipsum inceptos est sit sed inceptos. Habitant lobortis finibus habitasse arcu nec vulputate pretium lobortis. Quisque parturient mauris sed platea aptent facilisis metus. Duis semper felis placerat; molestie massa platea. Magna dapibus commodo commodo non augue nec mauris metus. Malesuada rutrum purus volutpat dis inceptos feugiat ac posuere. Bibendum duis conubia pharetra in fames hendrerit porttitor. Magnis tortor sem gravida sem consequat platea. Porttitor sagittis mauris conubia convallis, purus et. Lacus inceptos nullam lectus dui taciti ligula fermentum augue. Mi nascetur bibendum iaculis fusce semper nulla efficitur vitae. Facilisi habitant bibendum fusce dictum hac vivamus orci nisl. Tincidunt nam sollicitudin consequat quam etiam efficitur tincidunt. Sagittis sociosqu lorem varius morbi a. Cubilia auctor sollicitudin elit, molestie donec mollis platea sem. Euismod vulputate sociosqu placerat conubia rutrum etiam nibh. Vivamus efficitur gravida suscipit litora euismod; iaculis dis. Morbi sapien varius potenti netus finibus efficitur? Class neque nostra dictum laoreet dapibus nullam. Fermentum ridiculus sit odio laoreet justo a et tincidunt. Dis nam posuere metus rutrum sem ullamcorper efficitur magna. In ante sagittis donec egestas nullam netus lacus nec ultrices. Montes tortor aenean porttitor facilisi hac habitasse? Orci suscipit ullamcorper platea vulputate posuere congue aliquet augue. Dignissim venenatis mus suscipit tellus interdum turpis. Neque nisl nibh ex gravida aenean dui vivamus amet. Lacinia libero euismod ex elementum sed at tristique amet. Nulla quisque ultricies, et euismod mollis arcu dignissim odio. Ad volutpat turpis fames volutpat auctor egestas. Accumsan quam leo fringilla; euismod laoreet augue condimentum. Venenatis maximus gravida ultricies felis sociosqu molestie. Est suscipit rutrum penatibus consequat magnis aliquam velit lobortis. Varius purus fermentum ullamcorper donec dapibus curae scelerisque sapien. Inceptos sagittis rutrum odio ligula aenean fusce ac ultrices. Dapibus litora ipsum venenatis; vivamus dui scelerisque sem arcu sollicitudin. Metus habitant habitant aptent; dictum maximus ullamcorper. Dapibus netus proin sagittis fames lectus, integer et cursus. Pulvinar consectetur accumsan massa litora habitasse malesuada, pharetra lectus. Magnis pretium dictum interdum luctus nullam ridiculus torquent in. Porta auctor semper felis feugiat efficitur lectus fames. Ultricies suscipit sed fermentum laoreet; class et primis. Torquent libero quis non maecenas facilisi luctus. Lectus duis parturient mus eleifend facilisis pretium. Eget diam aliquam; penatibus fusce elit et. Per dictum suscipit molestie eleifend non non. Nec proin ad proin platea hendrerit magna semper rutrum. Quis himenaeos tempor donec potenti magna ad dui volutpat sollicitudin. Facilisi sapien massa porta per ultrices elementum. Convallis blandit vehicula montes natoque scelerisque ante. Sapien eget sollicitudin platea tempor torquent vel. Etiam semper ante ad est pellentesque purus aliquet bibendum. Est mauris rutrum turpis phasellus est potenti. ";
    printf("strlen %zu\n", strlen(msg2));  
    printf("strlen: %zu\n", ft_strlen(msg2));  

    
 /*
 * ft_strcpy
 */

    printf("\ntest3 ft_srtcpy with 0 size:\n");
    char *des = malloc(1);
    if (des == NULL) return 1;
    char *src = "";
    strcpy(des, src);
    printf("strcpy des = %s, len=%li\n", des, strlen(des));
    free(des);
    des=malloc(1);
    ft_strcpy(des, src);
    printf("ft_strcpy des = %s, len=%li\n", des, strlen(des));
    free(des);

    printf("\ntest4 ft_srtcpy with long text:\n");
    des = malloc(strlen(msg2));
    if (des == NULL) return 1;
    strcpy(des, msg2);
    printf("\nstrcpy res = %s, len=%li\n", des, strlen(des));
    free(des);
    char *des2 = malloc(strlen(msg2));
    ft_strcpy(des2, msg2);
    printf("\nft_strcpy des = %s, len=%li\n", des2, ft_strlen(des2));
    free(des2);
/* 
 * ft_strcmp
 */
    printf("\ntest5 ft_strcmp:\n");
    char *empty = "";
    char *notempty = "asd";
    char *notempty2 = "A";
    int original = strcmp(empty, empty);
    int my = ft_strcmp(empty, empty);
    
    printf("ft_strcmp two empty strs, strcmp result: %d, ft_strcmp res:%d\n",  original, my);
   
    original = strcmp(empty, notempty);
    my = ft_strcmp(empty, notempty);
    printf("ft_strcmp 1st empty strs, strcmp result: %d, ft_strcmp res:%d\n",  original, my);

    original = strcmp(notempty, empty);
    my = ft_strcmp(notempty, empty);
    printf("ft_strcmp 2st empty strs, strcmp result: %d, ft_strcmp res:%d\n",  original, my);


    original = strcmp(notempty, notempty2);
    my = ft_strcmp(notempty, notempty2);
    printf("ft_strcmp both not empty strs, strcmp result: %d, ft_strcmp res:%d\n",  original, my);


    original = strcmp(notempty2, notempty2);
    my = ft_strcmp(notempty2, notempty2);
    printf("ft_strcmp both not empty and equal strs, strcmp result: %d, ft_strcmp res:%d\n",  original, my);



 /* 
 * ft_write 
 * */
     printf("\ntest write\n");  
    errno = 0;
    int a = ft_write(1, "hello\n", 6);
    printf("ft_write correct, errno = %i\n", errno);
    printf("ft_write returned: %i\n", a);

    errno = 0;
    a = ft_write(4, "hello\n", 6);
    printf("ft_write incorrect, errno = %i\n", errno);
    printf("ft_write returned: %i\n", a);




/*
 * write
 */
    errno = 0;
    int b = write(1, "hello\n", 6);
    printf("write correct, errno = %i\n", errno);
    printf("write returned: %i\n", b);

    errno = 0;
    b = write(4, "hello\n", 6);
    printf("write incorrect, errno = %i\n", errno);
    printf("write returned: %i\n", b);

/* 
 * ft_read 
 */
     printf("\ntest read\n");  
     char buff[1024];
     int fd = open("./file.txt", O_RDONLY);
     errno = 0;
     int c = ft_read(fd, buff, 1024);  // Change the call to ft_read
     printf("ft_read correct, errno = %i\n", errno);
     printf("ft_read returned: %i\n", c);
     close(fd);


     fd = open("./file.txt", O_RDONLY);
    errno = 0;
    c = ft_read(12122121, buff, 1024);  // Change the call to ft_read
    printf("ft_read incorrect, errno = %i\n", errno);
    printf("ft_read returned: %i\n", c);
     close(fd);

 /*
 * read
 */

    fd = open("./file.txt", O_RDONLY);
    errno = 0;
    int d = read(fd, buff, 1024);  // Change the call to ft_read
    printf("read correct, errno = %i\n", errno);
    printf("read returned: %i\n", d);
    close(fd);


    fd = open("./file.txt", O_RDONLY);
    errno = 0;
    d = read(12122121, buff, 1024);  // Change the call to ft_read
    printf("read incorrect, errno = %i\n", errno);
    printf("read returned: %i\n", d);
    close(fd);

/*
 * ft_strdup
 */
    printf("\ntest strdup long str\n");
    
    char *std_dup = strdup(msg2);
    if (std_dup == NULL) printf("strdup failed\n");
    else {
       printf("strdup allocates : %ld\n", strlen(std_dup));
    }    

    char *ft_dup = ft_strdup(msg2);
    if (ft_dup == NULL) printf("ft_strdup failed\n");
    else {
       printf("ft_strdup allocates : %ld,\ntext: %s\n", strlen(ft_dup), ft_dup);
    }    

    if (strcmp(std_dup, ft_dup) == 0) {
        printf("ft_strdup works as strdup!\n");
    } else {
        printf("ft_strdup does NOT work like strdup.\n");
    }
    free(std_dup);
    free(ft_dup);
 

    printf("\ntest strdup empty str\n");
    std_dup = strdup("");

    if (ft_dup) printf("std strdup with empty str res: %ld\n", strlen(std_dup));
    else {
     printf("strdup is null\n");
    }
    ft_dup = ft_strdup("");
    if (ft_dup) printf("ft_strdup with empty str res: %ld\n", strlen(ft_dup));
    else {
     printf("ft_strdup is null\n");
    }
    return 0;
}

