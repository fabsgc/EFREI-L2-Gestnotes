<if condition="isset($formErrors) && count($formErrors) > 0">
	<div class="alert alert-error">
		<foreach loop="$formErrors as $key => $errors">
			<foreach loop="$errors as $key2 => $error">
				{$error}
				<if condition="count($errors) > $key2 + 1">
					<br />
				</if>
			</foreach>
			<if condition="count($formErrors) > $key + 1">
				<br />
			</if>
		</foreach>
	</div>
</if>
<if condition="isset($session['flash_success'])">
	<div class="alert alert-success">
		<div class="close" onclick="closeFlashMessage(this);"><span class="fa fa-times">&nbsp;</span> </div>
		{$session['flash_success']}
	</div>
</if>

<clear:flash/>