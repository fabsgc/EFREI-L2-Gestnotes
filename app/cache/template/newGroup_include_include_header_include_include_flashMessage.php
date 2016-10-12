<?php
?><?php if(isset($formErrors) && count($formErrors) > 0){ ?>
	<div class="alert alert-error">
		<?php foreach($formErrors as $key => $errors){ ?>
			<?php foreach($errors as $key2 => $error){ ?>
				<?php echo $error; ?>
				<?php if(count($errors) > $key2 + 1){ ?>
					<br />
				<?php } ?>
			<?php } ?>
			<?php if(count($formErrors) > $key + 1){ ?>
				<br />
			<?php } ?>
		<?php } ?>
	</div>	
<?php } ?>
<?php if(isset($session['flash_success'])){ ?>
	<div class="alert alert-success">
		<div class="close" onclick="closeFlashMessage(this);"><span class="fa fa-times">&nbsp;</span> </div>
		<?php echo $session['flash_success']; ?>
	</div>
<?php } ?>


