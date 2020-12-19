#include "mlx.h"

int main()
{
  void *mlx_ptr;
  void *win_ptr;
  void *img_ptr;
  int *pxl_ptr;
  int k;

  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx_42");
  img_ptr = mlx_new_image(mlx_ptr, 500, 500);
  pxl_ptr = (int *)mlx_get_data_addr(img_ptr, &k, &k, &k);

  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      pxl_ptr[i * 500 + j] = 0xFF0000;
      j += 32;
    }
    i += 32;
  }
  mlx_put_image_to_window ( mlx_ptr, win_ptr, img_ptr, 0,  0);
  mlx_loop(mlx_ptr);

}
