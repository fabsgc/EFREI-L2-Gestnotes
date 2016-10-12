<include src="include/header"/>

<a href="/admin/teacher/new/{$session['token']}" class="button right">Nouveau professeur</a>
<table class="table">
	<thead>
		<tr>
			<th class="matricule">Id</th>
			<th>Nom</th>
			<th>Email</th>
			<th class="action">Actions</th>
		<tr>
	</thead>
	<tbody>
		<foreach loop="$teachers as $data">
			<tr>
				<td>{$data['id']}</td>
				<td>
					<a href="/admin/teacher/see/{$data['id']}">{$data['personDetail']['firstName']} - {$data['personDetail']['name']}</a>
				</td>
				<td>{$data['personDetail']['email']}</td>
				<td class="action">
					<a href="/admin/teacher/edit/{$data['id']}/{$session['token']}"><span class="fa fa-pencil"></span></a>
					<a href="/admin/teacher/delete/{$data['id']}/{$session['token']}"><span class="fa fa-times"></span></a>
				</td>
			</tr>
		</foreach>
	<tbody>
</table>

<include src="include/footer"/>