function [psnr,mse] = psnr( x, y )
%
% [psnr,mse] = mse_psnr( x, y )
%
%   Mean Square Error (MSE) and Peak Signal to Noise Ratio (PSNR)
%   Matrixes x and y must have the same dimensions.
%   The range used to calculate PSNR is 255.
%

x = double(x(:));
y = double(y(:));

[Mx,Nx] = size(x);
[My,Ny] = size(y);
if Mx ~= My || Nx ~= Ny
	error( 'matrixes have different dimensions');
end
mse = sum((x-y).^2)/numel(x);
% mse = sum(sum((x-y).^2))/numel(x);
if( mse ~= 0 )
	psnr = 10*log10( 255^2 / mse );
else
	psnr = Inf;
end	
